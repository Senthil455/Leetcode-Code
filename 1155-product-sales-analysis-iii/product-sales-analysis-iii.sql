SELECT 
    Sales.product_id as product_id,
    Sales.year as first_year,
    Sales.quantity as quantity,
    Sales.price as price
FROM Sales
JOIN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) as Selftable  ON Sales.product_id = Selftable.product_id AND Sales.year = Selftable.first_year; 