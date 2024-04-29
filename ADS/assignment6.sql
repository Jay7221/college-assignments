USE ads_sample;

-- Create Customer Dimension Table
CREATE TABLE Dim_Customer (
    Customer_id INT PRIMARY KEY,
    Customer_name VARCHAR(255),
    City_id INT,
    First_order_date DATE
);

-- Create Store Dimension Table
CREATE TABLE Dim_Store (
    Store_id INT PRIMARY KEY,
    City_id INT,
    Phone VARCHAR(20)
);

-- Create Item Dimension Table
CREATE TABLE Dim_Item (
    Item_id INT PRIMARY KEY,
    Description VARCHAR(255),
    Size VARCHAR(50),
    Weight DECIMAL(10,2),
    Unit_price DECIMAL(10,2)
);

-- Create Time Dimension Table
CREATE TABLE Dim_Time (
    Time_id INT PRIMARY KEY,
    Order_date DATE
);

-- Create Order Fact Table
CREATE TABLE Fact_Order (
    Order_no INT PRIMARY KEY,
    Customer_id INT,
    Store_id INT,
    Item_id INT,
    Quantity_ordered INT,
    Ordered_price DECIMAL(10,2),
    Time_id INT
);

-- Add Foreign Key Constraints
ALTER TABLE Dim_Customer ADD CONSTRAINT fk_customer_city FOREIGN KEY (City_id) REFERENCES Dim_Store(City_id);
ALTER TABLE Dim_Store ADD CONSTRAINT fk_store_city FOREIGN KEY (City_id) REFERENCES Dim_Customer(City_id);
ALTER TABLE Fact_Order ADD CONSTRAINT fk_order_customer FOREIGN KEY (Customer_id) REFERENCES Dim_Customer(Customer_id);
ALTER TABLE Fact_Order ADD CONSTRAINT fk_order_store FOREIGN KEY (Store_id) REFERENCES Dim_Store(Store_id);
ALTER TABLE Fact_Order ADD CONSTRAINT fk_order_item FOREIGN KEY (Item_id) REFERENCES Dim_Item(Item_id);
ALTER TABLE Fact_Order ADD CONSTRAINT fk_order_time FOREIGN KEY (Time_id) REFERENCES Dim_Time(Time_id);


-- Insert sample data into Dim_Customer
INSERT INTO Dim_Customer (Customer_id, Customer_name, City_id, First_order_date) VALUES
(1, 'Rajesh Sharma', 1, '2023-01-15'),
(2, 'Priya Patel', 2, '2023-02-20'),
(3, 'Amit Singh', 1, '2023-03-10'),
(4, 'Deepika Gupta', 2, '2023-04-05');

-- Insert sample data into Dim_Store
INSERT INTO Dim_Store (Store_id, City_id, Phone) VALUES
(1, 1, '123-456-7890'),
(2, 1, '234-567-8901'),
(3, 2, '345-678-9012');

-- Insert sample data into Dim_Item
INSERT INTO Dim_Item (Item_id, Description, Size, Weight, Unit_price) VALUES
(1, 'Saree', 'Free size', 0.5, 499.99),
(2, 'Kurta', 'Large', 0.4, 399.99),
(3, 'Jeans', '32x34', 0.8, 799.99),
(4, 'T-Shirt', 'Medium', 0.2, 299.99);

-- Insert sample data into Dim_Time
INSERT INTO Dim_Time (Time_id, Order_date) VALUES
(1, '2023-01-15'),
(2, '2023-02-20'),
(3, '2023-03-10'),
(4, '2023-04-05');


-- Insert sample data into Fact_Order
INSERT INTO Fact_Order (Order_no, Customer_id, Store_id, Item_id, Quantity_ordered, Ordered_price, Time_id) VALUES
(1, 1, 1, 1, 2, 999.98, 1),
(2, 2, 2, 2, 1, 399.99, 2),
(3, 3, 2, 3, 1, 799.99, 3),
(4, 4, 3, 4, 3, 899.97, 4);


SELECT c.Customer_name, SUM(f.Ordered_price) AS Total_sales_amount
FROM Fact_Order f
JOIN Dim_Customer c ON f.Customer_id = c.Customer_id
GROUP BY c.Customer_name;

SELECT i.Description, SUM(f.Ordered_price) AS Total_sales_amount
FROM Fact_Order f
JOIN Dim_Item i ON f.Item_id = i.Item_id
GROUP BY i.Description;

SELECT s.Store_id, SUM(f.Ordered_price) AS Total_sales_amount
FROM Fact_Order f
JOIN Dim_Store s ON f.Store_id = s.Store_id
GROUP BY s.Store_id;
