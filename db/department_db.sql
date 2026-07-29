CREATE DATABASE lms;
USE lms;

CREATE TABLE department(
    department_id INT PRIMARY KEY, 
    name VARCHAR(100)
);

INSERT INTO 
    department(department_id,name) 
VALUES
(1,'CS'),
(2,'Electronics'),
(3,'Mechanical');

CREATE TABLE instructor(
    instructor_id INT PRIMARY KEY,
    name VARCHAR(100),
    department_id INT,
    salary INT DEFAULT 10000
);

ALTER TABLE 
    instructor 
ADD CONSTRAINT fk_department 
FOREIGN KEY (department_id) 
REFERENCES department(department_id);

INSERT INTO 
    instructor(instructor_id,name,department_id,salary) 
VALUES
(101,'Dr. Rao',1,95000), 
(102,'Dr. Mehta',2,88000),
(103,'Dr. Iyer',1,72000),
(104,'Dr. Sen',3,60000);

CREATE TABLE students(
    student_id INT PRIMARY KEY,
    name VARCHAR(100),
    department_id INT,
    dob CHAR(10)
);

ALTER TABLE 
    students
ADD CONSTRAINT fk_student_department
FOREIGN KEY (department_id)
REFERENCES department(department_id);

INSERT INTO 
    students(student_id,name,department_id,dob)
VALUES 
(1,'Aarav',1,'2003-05-14'), 
(2,'Diya',1,'2003-08-22'),
(3,'Kabir',2,'2003-01-30'), 
(4,'Meera',3,'2003-03-11'),
(5,'Rohan',1,'2003-07-19');


CREATE TABLE course(
    course_id INT PRIMARY KEY,
    name VARCHAR(100),
    department_id INT,
    instructor_id INT
);

ALTER TABLE 
    course
ADD CONSTRAINT fk_course_instructor
FOREIGN KEY (instructor_id)
REFERENCES instructor(instructor_id);

ALTER TABLE 
    course 
ADD CONSTRAINT fk_course_department
FOREIGN KEY(department_id)
REFERENCES department(department_id);


INSERT INTO 
    course(course_id, name,department_id ,instructor_id) 
VALUES 
(201,'DBMS',1,101), 
(202,'OS',1,103), 
(203,'Circuits',2,102), 
(204,'Thermo',3,104);


CREATE TABLE enrollment (
    student_id INT,
    course_id INT,
    grade CHAR(1),
    
    PRIMARY KEY(student_id,course_id)
);

ALTER TABLE 
    enrollment 
ADD CONSTRAINT fk_student_enrollment
FOREIGN KEY (student_id) 
REFERENCES students(student_id);

ALTER TABLE 
    enrollment 
ADD CONSTRAINT fk_course_enrolled
FOREIGN KEY (course_id)
REFERENCES course(course_id);


INSERT INTO 
    enrollment(student_id,course_id,grade)
VALUES
(1,201,'A'), 
(1,202,'B'), 
(2,201,'A'), 
(3,203,'B'), 
(5,201,'C');

