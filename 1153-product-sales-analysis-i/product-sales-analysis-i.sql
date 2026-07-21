-- Write your PostgreSQL query statement below
select Product.product_name , Sales.year , Sales.price from Sales , Product where Product.product_id =Sales.product_id ;