-- Write your PostgreSQL query statement below
SELECT d.name AS Department, e.name AS Employee, salary
FROM Employee e
JOIN Department d ON e.departmentId = d.id
WHERE salary IN (
    SELECT DISTINCT(salary)
    FROM Employee
    WHERE Employee.departmentId = d.id
    ORDER BY salary DESC
    LIMIT 3
)