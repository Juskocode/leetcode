SELECT
    d.name  AS Department,
    e.name  AS Employee,
    e.salary AS Salary
FROM (
    SELECT
        id,
        name,
        salary,
        departmentId,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS salary_rank
    FROM Employee
) AS e
JOIN Department AS d
    ON e.departmentId = d.id
WHERE e.salary_rank <= 3;
