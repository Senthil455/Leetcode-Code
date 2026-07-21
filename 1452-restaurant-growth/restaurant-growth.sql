-- Write your PostgreSQL query statement below


WITH day_sum_table AS (
    SELECT  visited_on, SUM(amount) AS day_sum
    FROM Customer
    GROUP BY visited_on
    ORDER BY visited_on
)

SELECT visited_on,
SUM(day_sum) OVER (ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount,
ROUND(AVG(day_sum) OVER (ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) as average_amount

FROM day_sum_table
OFFSET 6