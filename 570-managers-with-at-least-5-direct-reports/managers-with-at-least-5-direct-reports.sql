-- Write your PostgreSQL query statement below
select e1.name
from employee e1
join (
    select managerId,count(managerId) as cnt
    from employee 
    group by managerId
) e2
on e1.id=e2.managerId
where e2.cnt>=5;