-- Write your PostgreSQL query statement below
WITH movierating_in_february_2020 AS (
    SELECT *
    FROM MovieRating
    WHERE TO_CHAR(created_at, 'yyyy-mm') = '2020-02'
),

movie_title_with_highest_average_rating_in_february_2020 AS (
    SELECT title
    FROM movierating_in_february_2020
    INNER JOIN Movies
    USING(movie_id)
    GROUP BY movie_id, title
    ORDER BY AVG(rating) DESC,
            title ASC
    LIMIT 1
),

user_name_who_has_rated_the_greatest_number_of_movies AS (
    SELECT name
    FROM MovieRating
    INNER JOIN Users
    USING(user_id)
    GROUP BY user_id, name
    ORDER BY COUNT(movie_id) DESC,
            name ASC
    LIMIT 1
)

SELECT name AS results
FROM user_name_who_has_rated_the_greatest_number_of_movies

UNION ALL

SELECT title
FROM movie_title_with_highest_average_rating_in_February_2020;