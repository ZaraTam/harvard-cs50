SELECT title, rating FROM
movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010 AND rating IS NOT NULL
GROUP BY title
ORDER BY rating DESC;