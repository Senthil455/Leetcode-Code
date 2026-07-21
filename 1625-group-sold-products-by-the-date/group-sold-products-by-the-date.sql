--For each date -- find no of diff prod sold
--order prod name lexico, order by sell_date
--Output -- sell_date, num_sold , products

SELECT sell_date, COUNT(DISTINCT product) AS num_sold, 
STRING_AGG(DISTINCT product, ',' ORDER BY product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date