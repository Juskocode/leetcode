# Write your MySQL query statement below
SELECT 
ROUND(COUNT(a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2)
AS fraction
FROM 
(
    SELECT player_id, MIN(event_date) AS event_date
    FROM Activity
    GROUP BY player_id
) a
JOIN Activity b
ON a.player_id = b.player_id
AND DATEDIFF(b.event_date, a.event_date) = 1