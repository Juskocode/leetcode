# Write your MySQL query statement below
SELECT query_name,
    ROUND(AVG(rating / Queries.position), 2)
    AS quality,
    ROUND(SUM(IF(rating < 3, 1, 0)) / COUNT(*) * 100.0, 2)
    AS poor_query_percentage
FROM Queries

GROUP BY query_name