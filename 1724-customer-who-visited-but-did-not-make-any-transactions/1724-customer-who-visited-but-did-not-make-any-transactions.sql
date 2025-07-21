# Write your MySQL query statement below
SELECT  DISTINCT customer_id, COUNT(*) as count_no_trans FROM Visits
LEFT JOIN Transactions on Visits.visit_id = Transactions.visit_id
WHERE Transactions.visit_id is null
GROUP BY Visits.customer_id