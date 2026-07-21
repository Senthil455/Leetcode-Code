-- Write your PostgreSQL query statement below
select 
    case 
        when ((select count(id) from Seat) % 2 = 1) and (id = (select count(id) from Seat))
            then id
        when id % 2 = 1
            then id + 1
        else id - 1
    end
    as id,
    student
from Seat
order by id;