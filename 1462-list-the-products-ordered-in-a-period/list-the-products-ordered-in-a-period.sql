SELECT product_name, SUM(unit) AS unit
FROM Orders AS o
INNER JOIN Products
USING(product_id)
WHERE TO_CHAR(order_date, 'YYYY-MM') = '2020-02'
GROUP BY product_id, product_name
HAVING SUM(unit) >= 100;