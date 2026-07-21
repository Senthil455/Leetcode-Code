
-- Write your PostgreSQL query statement below
select case when e2.unique_id>=0 then e2.unique_id else null end as unique_id,e1.name 
from employees e1
left join employeeUNI e2 on e1.id=e2.id 