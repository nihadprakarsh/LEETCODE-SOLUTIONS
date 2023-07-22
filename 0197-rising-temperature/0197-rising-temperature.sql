# Write your MySQL query statement below
select w.id
from Weather w,Weather w1
where DATEDIFF(w.recordDate,w1.recordDate) = 1 and w.temperature > w1.temperature;