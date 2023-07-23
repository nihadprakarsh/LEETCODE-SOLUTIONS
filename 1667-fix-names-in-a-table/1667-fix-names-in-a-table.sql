# Write your MySQL query statement below
select user_id, concat(UPPER(substr(name,1,1)),'',LOWER(substr(name,2,length(name)))) as name
from Users
order by user_id asc;
