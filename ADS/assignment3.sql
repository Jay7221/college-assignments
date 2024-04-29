use ads_sample;

drop table if exists classroom, course, department,instructor, section, teaches, student, takes, time_slot, prereq, advisor;


-- Table: classroom
CREATE TABLE classroom (
    building VARCHAR(30),
    room_number INT,
    capacity INT,
    PRIMARY KEY (building, room_number)
);

-- Table: department
CREATE TABLE department (
    dept_name VARCHAR(30),
    building VARCHAR(30),
    budget DECIMAL(10, 2),
    PRIMARY KEY (dept_name)
);

-- Table: time_slot
CREATE TABLE time_slot (
    time_slot_id VARCHAR(30),
    day VARCHAR(30),
    start_time TIME,
    end_time TIME,
    PRIMARY KEY (time_slot_id)
);

-- Table: course
CREATE TABLE course (
    course_id VARCHAR(30),
    title VARCHAR(30),
    dept_name VARCHAR(30),
    credits INT,
    PRIMARY KEY (course_id),
    FOREIGN KEY (dept_name) REFERENCES department(dept_name)
);

-- Table: instructor
CREATE TABLE instructor (
    ID VARCHAR(30),
    name VARCHAR(30),
    dept_name VARCHAR(30),
    salary DECIMAL(10, 2),
    PRIMARY KEY (ID),
    FOREIGN KEY (dept_name) REFERENCES department(dept_name)
);

-- Table: section
CREATE TABLE section (
    course_id VARCHAR(30),
    sec_id VARCHAR(30),
    semester VARCHAR(30),
    year INT,
    building VARCHAR(30),
    room_number INT,
    time_slot_id VARCHAR(30),
    PRIMARY KEY (course_id, sec_id, semester, year),
    FOREIGN KEY (course_id) REFERENCES course(course_id),
    FOREIGN KEY (building, room_number) REFERENCES classroom(building, room_number),
    FOREIGN KEY (time_slot_id) REFERENCES time_slot(time_slot_id)
);

-- Table: teaches
CREATE TABLE teaches (
    ID VARCHAR(30),
    course_id VARCHAR(30),
    sec_id VARCHAR(30),
    semester VARCHAR(30),
    year INT,
    PRIMARY KEY (ID, course_id, sec_id, semester, year),
    FOREIGN KEY (ID) REFERENCES instructor(ID),
    FOREIGN KEY (course_id, sec_id, semester, year) REFERENCES section(course_id, sec_id, semester, year)
);

-- Table: student
CREATE TABLE student (
    ID VARCHAR(30),
    name VARCHAR(30),
    dept_name VARCHAR(30),
    tot_cred INT,
    PRIMARY KEY (ID),
    FOREIGN KEY (dept_name) REFERENCES department(dept_name)
);

-- Table: takes
CREATE TABLE takes (
    ID VARCHAR(30),
    course_id VARCHAR(30),
    sec_id VARCHAR(30),
    semester VARCHAR(30),
    year INT,
    grade VARCHAR(30),
    PRIMARY KEY (ID, course_id, sec_id, semester, year),
    FOREIGN KEY (ID) REFERENCES student(ID),
    FOREIGN KEY (course_id, sec_id, semester, year) REFERENCES section(course_id, sec_id, semester, year)
);

-- Table: advisor
CREATE TABLE advisor (
    s_ID VARCHAR(30),
    i_ID VARCHAR(30),
    PRIMARY KEY (s_ID),
    FOREIGN KEY (s_ID) REFERENCES student(ID),
    FOREIGN KEY (i_ID) REFERENCES instructor(ID)
);



-- Table: prereq
CREATE TABLE prereq (
    course_id VARCHAR(30),
    prereq_id VARCHAR(30),
    PRIMARY KEY (course_id, prereq_id),
    FOREIGN KEY (course_id) REFERENCES course(course_id),
    FOREIGN KEY (prereq_id) REFERENCES course(course_id)
);



-- Classroom
INSERT INTO classroom (building, room_number, capacity) VALUES
('EngineeringBuilding', 101, 50),
('ScienceHall', 201, 75);

-- Classroom
INSERT INTO Classrooms (building, room_number, capacity) VALUES
('EngineeringBuilding', 101, 50),UsersUsers
('ScienceHall', 201, 75);

-- Department
INSERT INTO department (dept_name, building, budget) VALUES
('ComputerScience', 'MainBuilding', 100000),
('Mathematics', 'MathBuilding', 80000);

-- Time Slot
INSERT INTO time_slot (time_slot_id, day, start_time, end_time) VALUES
('MorningSlot', 'Monday', '08:00:00', '10:00:00'),
('AfternoonSlot', 'Wednesday', '12:00:00', '14:00:00');

-- Course
INSERT INTO course (course_id, title, dept_name, credits) VALUES
('CS101', 'Introduction to Programming', 'ComputerScience', 3),
('MATH201', 'Calculus I', 'Mathematics', 4);

-- Instructor
INSERT INTO instructor (ID, name, dept_name, salary) VALUES
('CS001', 'Professor Smith', 'ComputerScience', 60000),
('MATH002', 'Professor Johnson', 'Mathematics', 55000);

-- Section
INSERT INTO section (course_id, sec_id, semester, year, building, room_number, time_slot_id) VALUES
('CS101', 'SectionA', 'Fall', 2023, 'EngineeringBuilding', 101, 'MorningSlot'),
('MATH201', 'SectionB', 'Spring', 2024, 'ScienceHall', 201, 'AfternoonSlot');

-- Teaches
INSERT INTO teaches (ID, course_id, sec_id, semester, year) VALUES
('CS001', 'CS101', 'SectionA', 'Fall', 2023),
('MATH002', 'MATH201', 'SectionB', 'Spring', 2024);

-- Student
INSERT INTO student (ID, name, dept_name, tot_cred) VALUES
('S001', 'Jane Doe', 'ComputerScience', 60),
('S002', 'Bob Johnson', 'Mathematics', 45);

-- Takes
INSERT INTO takes (ID, course_id, sec_id, semester, year, grade) VALUES
('S001', 'CS101', 'SectionA', 'Fall', 2023, 'A'),
('S002', 'MATH201', 'SectionB', 'Spring', 2024, 'B+');

-- Advisor
INSERT INTO advisor (s_ID, i_ID) VALUES
('S001', 'CS001'),
('S002', 'MATH002');

-- Prereq
INSERT INTO prereq (course_id, prereq_id) VALUES
('CS101', 'MATH201');

