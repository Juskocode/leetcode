WITH login_data AS (
  SELECT
    player_id,
    event_date,
    MIN(event_date) OVER (PARTITION BY player_id) AS first_login
  FROM
    Activity
)
SELECT
  ROUND(
    SUM(event_date = DATE_ADD(first_login, INTERVAL 1 DAY))
    / COUNT(DISTINCT player_id)
  , 2) AS fraction
FROM
  login_data;
