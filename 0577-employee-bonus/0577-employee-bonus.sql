# Write your MySQL query statement below
SELECT name, bonus FROM Employee
LEFT JOIN Bonus ON Employee.empId = Bonus.empId
Where Bonus.bonus < 1000 OR Bonus.bonus is null