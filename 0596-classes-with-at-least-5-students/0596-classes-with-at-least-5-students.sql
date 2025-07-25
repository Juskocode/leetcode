# Write your MySQL query statement below
SELECT a.class FROM Courses a
LEFT JOIN Courses b ON a.class = b.class
GROUP BY a.class
HAVING COUNT(b.class) / 2 >= 5