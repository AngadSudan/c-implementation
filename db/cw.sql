-- get student name , dept name, and their grades for courses for semester 2023

SELECT 
    s.name,d.dept_name,
    e.grade,c.course_name 
FROM 
    Student s, Department d,
    Enrollment e,Course c 
WHERE 
    s.dept_id = d.dept_id 
    AND e.student_id=s.student_id 
    AND e.semester="Fall2023" 
    AND e.course_id = c.course_id 
ORDER BY d.dept_name,s.name;

-- get teacher, dept and number of students taught

select 
    i.name,d.dept_name,s.num_of_students 
FROM 
    Instructor i,Department d, 
    (
        SELECT 
            dd.dept_id, COUNT(ss.name) as num_of_students 
        FROM 
            Department dd, Student ss 
        WHERE dd.dept_id = ss.dept_id 
        GROUP BY dept_id
    ) s 
WHERE s.dept_id=d.dept_id;

-- course with instructor and the list of students enrolled in each course schedule

SELECT 
    c.course_name, i.name,
    s.room_no,s.day_of_week,
    e.enrollment_count 
FROM 
    Course c, Instructor i,Course_Schedule s,
    (
        SELECT 
            ee.course_id,COUNT(ss.student_id) as enrollment_count 
        FROM 
            Enrollment ee, Student ss 
        WHERE 
            ss.student_id=ee.student_id 
        GROUP BY ee.course_id
    ) e 
WHERE 
    c.instructor_id=i.instructor_id AND s.course_id = c.course_id;

-- student in 1 course other than his own dept 

SELECT 
    s.name, s.dept_id,
    c.course_name, c.dept_id
FROM 
    Student s, Enrollment e, Course c
WHERE
    s.student_id = e.student_id 
    AND e.course_id = c.course_id
    AND c.dept_id != s.dept_id;

-- pairs of students 
SELECT 
    s1.name AS student1,
    s2.name AS student2,
    c.course_name,
    e1.semester,
    e1.grade AS grade1,
    e2.grade AS grade2
FROM 
    Enrollment e1, Enrollment e2,
    Student s1, Student s2,
    Course c
WHERE
    e1.course_id = e2.course_id
    AND e1.semester = e2.semester
    AND e1.grade != e2.grade
    AND e1.student_id < e2.student_id
    AND e1.student_id = s1.student_id
    AND e2.student_id = s2.student_id
    AND e1.course_id = c.course_id;

-- books with author having more catalouge than 1 dept
SELECT 
    title
FROM 
    Book
WHERE 
    author IN (
        SELECT author
        FROM Book
        GROUP BY author
        HAVING COUNT(DISTINCT dept_id) > 1
    ); 

