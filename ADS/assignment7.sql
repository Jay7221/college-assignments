USE ads_sample;
-- Product Dimension Table
CREATE TABLE product (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(255),
    category VARCHAR(255),
    brand VARCHAR(255)
);

-- Customer Dimension Table
CREATE TABLE customer (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255),
    address VARCHAR(255),
    contact_info VARCHAR(255)
);

-- Store Dimension Table
CREATE TABLE store (
    store_id INT PRIMARY KEY,
    store_name VARCHAR(255),
    location VARCHAR(255),
    manager VARCHAR(255)
);

-- Date Dimension Table
CREATE TABLE date_dimension (
    date_id INT PRIMARY KEY,
    sales_date DATE,
    day_of_week VARCHAR(10),
    month VARCHAR(10),
    quarter VARCHAR(10),
    year INT,
    public_holidays VARCHAR(255)
);

-- Time Dimension Table
CREATE TABLE time_dimension (
    time_id INT PRIMARY KEY,
    hour INT,
    minute INT,
    time_band VARCHAR(20)
);
-- Sales Person Dimension Table
CREATE TABLE sales_person (
    sales_person_id INT PRIMARY KEY,
    sales_person_name VARCHAR(255),
    department VARCHAR(255)
);

-- Sales Fact Table
CREATE TABLE sales_fact (
    sales_id INT PRIMARY KEY,
    sales_date_key INT,
    sales_time_key INT,
    invoice_number VARCHAR(50),
    sales_person_id INT,
    store_id INT,
    customer_id INT,
    product_id INT,
    actual_cost DECIMAL(10, 2),
    total_sales DECIMAL(10, 2),
    quantity_sold INT,
    fact_record_count INT,
    FOREIGN KEY (sales_date_key) REFERENCES date_dimension (date_id),
    FOREIGN KEY (sales_time_key) REFERENCES time_dimension (time_id),
    FOREIGN KEY (sales_person_id) REFERENCES sales_person (sales_person_id),
    FOREIGN KEY (store_id) REFERENCES store (store_id),
    FOREIGN KEY (customer_id) REFERENCES customer (customer_id),
    FOREIGN KEY (product_id) REFERENCES product (product_id)
);


-- Sample data for product dimension
INSERT INTO product (product_id, product_name, category, brand)
VALUES
    (1, 'Laptop', 'Electronics', 'ABC'),
    (2, 'T-shirt', 'Apparel', 'XYZ'),
    (3, 'Smartphone', 'Electronics', 'PQR');

-- Sample data for customer dimension with Indian names
INSERT INTO customer (customer_id, customer_name, address, contact_info)
VALUES
    (1, 'Rajesh Kumar', '123 Main St', '123-456-7890'),
    (2, 'Priya Sharma', '456 Oak St', '456-789-0123'),
    (3, 'Aarav Gupta', '789 Elm St', '789-012-3456'),
    (4, 'Ananya Singh', '456 Pine St', '987-654-3210'),
    (5, 'Neha Patel', '789 Maple St', '567-890-1234');

-- Sample data for store dimension with Indian names
INSERT INTO store (store_id, store_name, location, manager)
VALUES
    (1, 'X-Mart Downtown', 'Downtown', 'Amit Patel'),
    (2, 'X-Mart Suburb', 'Suburb', 'Preeti Shah'),
    (3, 'X-Mart Mall', 'Mall', 'Rahul Singh'),
    (4, 'X-Mart Plaza', 'Plaza', 'Deepak Mehta');

-- Sample data for date dimension
INSERT INTO date_dimension (date_id, sales_date, day_of_week, month, quarter, year, public_holidays)
VALUES
    (1, '2024-03-01', 'Monday', 'March', 'Q1', 2024, 'None'),
    (2, '2024-03-02', 'Tuesday', 'March', 'Q1', 2024, 'None'),
    (3, '2024-03-03', 'Wednesday', 'March', 'Q1', 2024, 'Holi');

-- Sample data for time dimension
INSERT INTO time_dimension (time_id, hour, minute, time_band)
VALUES
    (1, 8, 0, 'Morning'),
    (2, 12, 0, 'Afternoon'),
    (3, 18, 0, 'Evening');
    
-- Sample data for sales person dimension with Indian names
INSERT INTO sales_person (sales_person_id, sales_person_name, department)
VALUES
    (1, 'Aarav Kumar', 'Electronics'),
    (2, 'Priya Sharma', 'Apparel'),
    (3, 'Rohan Patel', 'Electronics'),
    (4, 'Kavya Singh', 'Apparel'),
    (5, 'Neha Gupta', 'Electronics');


-- Sample data for sales fact table
INSERT INTO sales_fact (sales_id, sales_date_key, sales_time_key, invoice_number, sales_person_id, store_id, customer_id, product_id, actual_cost, total_sales, quantity_sold, fact_record_count)
VALUES
    (1, 1, 1, 'INV-001', 1, 1, 1, 1, 1000.00, 1500.00, 5, 1),
    (2, 2, 2, 'INV-002', 2, 2, 2, 2, 500.00, 750.00, 3, 1),
    (3, 3, 3, 'INV-003', 3, 3, 3, 3, 1200.00, 1800.00, 4, 1),
    (4, 1, 1, 'INV-004', 4, 4, 4, 1, 900.00, 1200.00, 3, 1),
    (5, 2, 2, 'INV-005', 5, 1, 5, 2, 800.00, 1000.00, 2, 1);


-- Query to retrieve sales information for a specific date and product category
SELECT
    d.sales_date,
    p.category,
    SUM(sf.total_sales) AS total_sales,
    SUM(sf.quantity_sold) AS total_quantity_sold
FROM
    sales_fact sf
JOIN
    date_dimension d ON sf.sales_date_key = d.date_id
JOIN
    product p ON sf.product_id = p.product_id
WHERE
    d.sales_date = '2024-03-01' -- Specify the date
    AND p.category = 'Electronics' -- Specify the product category
GROUP BY
    d.sales_date, p.category;
    
    
    
SELECT
    s.store_id,
    d.sales_date,
    SUM(sf.total_sales) AS total_sales,
    SUM(sf.actual_cost) AS total_cost,
    SUM(sf.total_sales - sf.actual_cost) AS total_profit
FROM
    sales_fact sf
JOIN
    date_dimension d ON sf.sales_date_key = d.date_id
JOIN
    store s ON sf.store_id = s.store_id
GROUP BY
    s.store_id, d.sales_date;



SELECT
    d.month,
    SUM(sf.total_sales) AS total_sales,
    SUM(sf.actual_cost) AS total_cost,
    SUM(sf.total_sales - sf.actual_cost) AS total_profit
FROM
    sales_fact sf
JOIN
    date_dimension d ON sf.sales_date_key = d.date_id
GROUP BY
    d.month;

SELECT
    t.time_band,
    SUM(sf.total_sales) AS total_sales
FROM
    sales_fact sf
JOIN
    time_dimension t ON sf.sales_time_key = t.time_id
GROUP BY
    t.time_band;

SELECT
    p.product_name,
    s.location,
    SUM(sf.quantity_sold) AS total_quantity_sold
FROM
    sales_fact sf
JOIN
    product p ON sf.product_id = p.product_id
JOIN
    store s ON sf.store_id = s.store_id
GROUP BY
    p.product_name, s.location
ORDER BY
    total_quantity_sold DESC;


SELECT
    d.year,
    d.month,
    SUM(sf.total_sales) AS total_sales
FROM
    sales_fact sf
JOIN
    date_dimension d ON sf.sales_date_key = d.date_id
GROUP BY
    d.year, d.month;


SELECT
    d.day_of_week,
    SUM(sf.total_sales) AS total_sales
FROM
    sales_fact sf
JOIN
    date_dimension d ON sf.sales_date_key = d.date_id
GROUP BY
    d.day_of_week
ORDER BY
    total_sales DESC;
