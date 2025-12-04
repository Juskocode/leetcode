SELECT e2.name AS Employee
FROM Employee AS e1
INNER JOIN Employee AS e2
ON e1.id = e2.managerID
WHERE e1.salary < e2.salary