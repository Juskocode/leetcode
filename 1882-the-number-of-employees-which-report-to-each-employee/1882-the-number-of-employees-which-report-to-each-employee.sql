# Write your MySQL query statement below
SELECT b.employee_id, b.name,
    COUNT(a.reports_to) AS reports_count,
    ROUND(AVG(a.age)) AS average_age
FROM Employees a

JOIN Employees b ON b.employee_id = a.reports_to

GROUP BY employee_id

ORDER BY employee_id
