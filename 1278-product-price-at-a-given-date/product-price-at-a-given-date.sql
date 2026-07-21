-- Write your PostgreSQL query statement below
with cte as ( 
select product_id, new_price from Products 
where  (product_id, change_date) in (  
    select product_id, max(change_date) as latest_date
    from Products
    where change_date <= '2019-08-16'
    group by 1 )
)

select distinct p.product_id, coalesce(cte.new_price,10) as price from
Products p
left join
cte
on p.product_id = cte.product_id
;


