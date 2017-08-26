#1: Student Department Leetcode 580

SELECT dept_name, count(student_id) AS student_number
FROM student RIGHT JOIN department ON student.dept_id = department.dept_id
GROUP BY dept_name
ORDER BY student_number DESC, dept_name;

#2: Investment Leetcode 585

SELECT SUM(TIV_2016) AS TIV_2016
FROM insurance AS i1
WHERE (SELECT COUNT(PID) FROM insurance AS i2 WHERE i1.LAT=i2.LAT AND i1.LON=i2.LON) = 1
AND (SELECT COUNT(PID) FROM insurance AS i3 WHERE i1.TIV_2015=i3.TIV_2015) > 1;

#3: Tree, root, leaf, inner node Leetcode 608

SELECT t.id AS Id,(
CASE
WHEN t.p_id IS NULL THEN 'Root'
WHEN t.id IN (SELECT p_id FROM tree) THEN 'Inner'
ELSE 'Leaf' END
) AS Type
FROM tree AS t;
