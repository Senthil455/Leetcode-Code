-- Write your PostgreSQL query statement below
select query_name,
    round(avg(rating*1.0/position),2) as quality,
    round(count(*) filter (where rating<3)*100.0/count(*),2) as poor_query_percentage
from queries
group by query_name;