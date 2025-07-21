# Write your MySQL query statement below
SELECT Signups.user_id, 
ROUND(
    AVG(
        IF(Confirmations.action = 'confirmed', 1, 0)
    )
,2) AS confirmation_rate
FROM Signups

LEFT JOIN Confirmations ON Confirmations.user_id = Signups.user_id

GROUP BY Signups.user_id