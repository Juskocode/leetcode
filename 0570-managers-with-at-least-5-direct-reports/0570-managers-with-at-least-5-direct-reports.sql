# Write your MySQL query statement below
SELECT a.name FROM Employee a
LEFT JOIN Employee b ON a.id = b.managerId
GROUP BY a.id, a.name
HAVING COUNT(b.managerId) >= 5