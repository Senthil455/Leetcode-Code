-- Write your PostgreSQL query statement below
select p1.project_id,round(avg(e1.experience_years),2) as average_years
from Project p1
join employee e1
on p1.employee_id=e1.employee_id
group by p1.project_id;