CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      with cte as(
          select *,DENSE_RANK() over(order by salary desc)
          as r
          from Employee)
      
      select IFNULL((select salary from cte where r=N limit 1),null)
  );
END