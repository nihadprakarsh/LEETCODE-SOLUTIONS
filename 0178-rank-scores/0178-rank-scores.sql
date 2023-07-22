# Write your MySQL query statement belo
SELECT SCORE, DENSE_RANK() OVER(ORDER BY SCORE DESC)
as 'rank'
FROM Scores 
ORDER BY Score DESC;