# Write your MySQL query statement below
SELECT * FROM Cinema
WHERE id % 2 != 0 AND description NOT LIKE '%boring%'
ORDER BY rating DESC