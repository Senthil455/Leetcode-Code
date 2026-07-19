-- Write your PostgreSQL query statement below
select TO_CHAR(trans_date, 'YYYY-MM') as month,
country,
(count(*)) as trans_count,
(count(*) filter (where state='approved')) as approved_count,
COALESCE(sum(amount),0) as trans_total_amount,
COALESCE(sum(amount) filter (where state='approved'),0) as approved_total_amount
from Transactions
group by month,country;