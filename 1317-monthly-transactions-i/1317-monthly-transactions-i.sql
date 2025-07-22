# Write your MySQL query statement below
SELECT DATE_FORMAT(Transactions.trans_date, '%Y-%m') AS month, Transactions.country,

COUNT(Transactions.state) AS trans_count,
SUM(IF(Transactions.state = 'approved', 1, 0)) AS approved_count,

SUM(Transactions.amount) AS trans_total_amount,
SUM(IF(Transactions.state = 'approved', Transactions.amount, 0)) AS approved_total_amount

FROM Transactions

GROUP BY YEAR(Transactions.trans_date), MONTH(Transactions.trans_date), Transactions.country