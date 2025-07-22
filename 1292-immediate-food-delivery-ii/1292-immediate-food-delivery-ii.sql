# Write your MySQL query statement below
SELECT
    ROUND(SUM(IF(first_od = first_pdd, 1, 0)) / COUNT(*) * 100.0, 2) AS immediate_percentage
FROM (
    SELECT 
        MIN(order_date) AS first_od,
        MIN(customer_pref_delivery_date) AS first_pdd
    FROM Delivery
    GROUP BY customer_id
    ) AS first_dt;
