-- Write your PostgreSQL query statement below
select s1.student_id, s1.student_name, s2.subject_name, count(e1.subject_name) as attended_exams
from subjects s2 
cross join Students s1
left join examinations e1 
on s1.student_id = e1.student_id
and s2.subject_name = e1.subject_name
group by s1.student_id,s1.student_name,s2.subject_name
order by s1.student_id,s2.subject_name;