CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct(salary) from employee order by salary DESC LIMIT 1 OFFSET N
  );
END