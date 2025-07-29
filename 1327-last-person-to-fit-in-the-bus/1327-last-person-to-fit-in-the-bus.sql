# Write your MySQL query statement below
SELECT Name as person_name FROM (
    SELECT 
    turn AS Turn, person_id AS ID,
    person_name AS Name, weight AS Weight,
    SUM(Weight) OVER (ORDER BY Turn) AS Total_Weight
    FROM Queue
) q
WHERE Total_Weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;