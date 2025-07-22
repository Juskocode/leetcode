# Write your MySQL query statement below
SELECT Register.contest_id,
    ROUND((COUNT(Register.user_id) / (SELECT COUNT(*) FROM Users)) * 100.0, 2) AS percentage
FROM Register

GROUP BY Register.contest_id

ORDER BY percentage DESC, Register.contest_id ASC