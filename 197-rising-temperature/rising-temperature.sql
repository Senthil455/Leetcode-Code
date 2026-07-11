-- Write your PostgreSQL query statement below
select w1.id
from Weather w1
join weather w2
ON w1.recordDate- w2.recordDate = 1
where w1.temperature>w2.temperature;