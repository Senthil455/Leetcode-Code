-- Write your PostgreSQL query statement below
select p1.product_id,COALESCE(ROUND(SUM(p1.price * p2.units)*1.0 / SUM(p2.units), 2),0) AS average_price
from prices p1
left join unitssold p2
on p1.product_id=p2.product_id
AND p2.purchase_date BETWEEN p1.start_date AND p1.end_date
group by p1.product_id;