# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINct subject_id) AS cnt FROM Teacher
GROUP BY teacher_id