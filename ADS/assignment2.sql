USE ads_sample;

-- I. MySQL / PSM Review
-- 1. Create a table called test_table with 2 columns RecordNumber (type : Number(3)) and CurrentDate (type : Date)). Write a procedure in PSM which will insert 50 records into test_table. Insert the current date value into the table.
CREATE TABLE test_table(
	RecordNumber INT,
    CurrentDate DATE
);

DELIMITER //
CREATE PROCEDURE insert_records()
BEGIN
    DECLARE i INT DEFAULT 1;

    WHILE i <= 50 DO
        INSERT INTO test_table (RecordNumber, CurrentDate) VALUES (i, CURDATE());
        SET i = i + 1;
    END WHILE;
END //
DELIMITER ;

SELECT * from test_table;
CALL insert_records;
SELECT * from test_table;

-- Create a products table products(ProductID number(4),category char(3),detail varchar2(30),price number(10,2),stock number(5)). Insert the sample data. Write PSM procedure with two arguments X & Y which will increase price by X% for all products in category Y. X and Y will be given by user.

CREATE TABLE products (
    ProductID INT,
    category CHAR(4),
    detail VARCHAR(100),
    price DECIMAL(10,2),
    stock INT
);

INSERT INTO products (ProductID, category, detail, price, stock)
VALUES
    (1, 'LAP', 'High-Performance Laptop', 1299.99, 30),
    (2, 'LAP', 'Budget Laptop', 699.99, 50),
    (3, 'PHN', 'Flagship Smartphone', 999.99, 20),
    (4, 'PHN', 'Mid-Range Smartphone', 499.99, 40),
    (5, 'HDR', 'Wireless Over-Ear Headphones', 129.95, 25),
    (6, 'HDR', 'In-Ear Noise-Canceling Headphones', 79.95, 30),
    (7, 'CAM', 'Mirrorless Camera with Lens Kit', 899.50, 15),
    (8, 'CAM', 'Compact Digital Camera', 349.50, 20),
    (9, 'SSD', '1TB NVMe Solid State Drive', 149.99, 10),
    (10, 'SSD', '500GB SATA Solid State Drive', 89.99, 15);

SELECT * FROM products;

DELIMITER //

CREATE PROCEDURE update_prices(IN X DECIMAL(5,2), IN Y CHAR(3))
BEGIN
    UPDATE products
    SET price = price * (1 + X / 100)
    WHERE category = Y;
END //

DELIMITER ;

SET SQL_SAFE_UPDATES = 0;

CALL update_prices(10, 'LAP');
SELECT * FROM products;




-- II. Object Relational Databases
-- 1. Create Object Table containing field “name” of size 50 characters and member function “countNoOfWords” which returns the no. of words in “name” field. Demonstrate the working by entering different data.

CREATE TABLE ObjectTable (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50)
);

DELIMITER //
CREATE FUNCTION countNoOfWords(nameValue VARCHAR(50)) RETURNS INT deterministic
BEGIN
    DECLARE wordCount INT;
    SET wordCount = 0;
    
    IF nameValue is NOT NULL THEN
		SET wordCount = LENGTH(nameValue) - LENGTH(REPLACE(nameValue, ' ', '')) + 1;
    END IF;
    
    RETURN wordCount;
END //
DELIMITER ;


INSERT INTO ObjectTable (name) VALUES ('This is a sample text');
INSERT INTO ObjectTable (name) VALUES ('Another example with more words');
INSERT INTO ObjectTable (name) VALUES ('SingleWord');

SELECT id, name, countNoOfWords(name) AS wordCount FROM ObjectTable;


-- 2. Create an address type with the following attributes : address, city, state & pincode.
CREATE TABLE AddressTable(
	address VARCHAR(150),
    city VARCHAR(20),
    state VARCHAR(50),
    country VARCHAR(20),
    pincode VARCHAR(15)
);

-- Inserting data into AddressTable
INSERT INTO AddressTable (address, city, state, country, pincode)
VALUES
    ('123 Main Street', 'Mumbai', 'Maharashtra', 'India', '400001'),
    ('456 Park Avenue', 'Pune', 'Maharashtra', 'India', '411001'),
    ('789 Oak Lane', 'Nagpur', 'Maharashtra', 'India', '440001'),
    ('101 Pine Road', 'Nashik', 'Maharashtra', 'India', '422001'),
    ('202 Maple Drive', 'Aurangabad', 'Maharashtra', 'India', '431001'),
    ('303 Cedar Street', 'Thane', 'Maharashtra', 'India', '400601');



DELIMITER //

CREATE PROCEDURE ExtractAddressesByKeyword(IN keyword VARCHAR(50))
BEGIN
    SELECT *
    FROM AddressTable
    WHERE address LIKE CONCAT('%', keyword, '%')
       OR city LIKE CONCAT('%', keyword, '%')
       OR state LIKE CONCAT('%', keyword, '%')
       OR country LIKE CONCAT('%', keyword, '%')
       OR pincode LIKE CONCAT('%', keyword, '%');
END //

DELIMITER ;

DELIMITER //

CREATE PROCEDURE CountWordsInField(IN fieldName VARCHAR(50))
BEGIN
    SELECT 
        LENGTH(address) - LENGTH(REPLACE(address, ' ', '')) + 1 AS wordsInAddress,
        LENGTH(city) - LENGTH(REPLACE(city, ' ', '')) + 1 AS wordsInCity,
        LENGTH(state) - LENGTH(REPLACE(state, ' ', '')) + 1 AS wordsInState,
        LENGTH(country) - LENGTH(REPLACE(country, ' ', '')) + 1 AS wordsInCountry,
        LENGTH(pincode) - LENGTH(REPLACE(pincode, ' ', '')) + 1 AS wordsInPincode
    FROM AddressTable;
END //

DELIMITER ;


CALL ExtractAddressesByKeyword("Nashik");
CALL CountWordsInField('address');

-- 3. Create a user defined data type course_Type with 2 attributes course_id, description

CREATE TABLE CourseTable (
    course_id INT PRIMARY KEY,
    description VARCHAR(255)
);

DELIMITER //

-- Procedure to Insert a Row into CourseTable
CREATE PROCEDURE InsertCourse(IN courseId INT, IN courseDescription VARCHAR(255))
BEGIN
    INSERT INTO CourseTable (course_id, description) VALUES (courseId, courseDescription);
END //

-- Procedure to Retrieve All Rows from CourseTable
CREATE PROCEDURE GetAllCourses()
BEGIN
    SELECT * FROM CourseTable;
END //

-- Procedure to Retrieve Courses with a Specific ID
CREATE PROCEDURE GetCourseById(IN courseId INT)
BEGIN
    SELECT * FROM CourseTable WHERE course_id = courseId;
END //

DELIMITER ;

-- Inserting data into CourseTable
CALL InsertCourse(1, 'Introduction to Programming');
CALL InsertCourse(2, 'Database Management Systems');
CALL InsertCourse(3, 'Data Structures and Algorithms');
CALL InsertCourse(4, 'Web Development');
CALL InsertCourse(5, 'Machine Learning');

CALL GetAllCourses();
CALL GetCourseById(3);
