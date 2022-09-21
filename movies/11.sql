SELECT title FROM MOVIES, RATINGS WHERE id IN (SELECT movie_id FROM RATINGS WHERE movie_id IN (SELECT movie_id FROM PEOPLE, STARS WHERE PEOPLE.id = STARS.person_id AND PEOPLE.name = "Chadwick Boseman")) AND MOVIES.id = RATINGS.movie_id ORDER BY RATINGS.RATING DESC LIMIT 5;