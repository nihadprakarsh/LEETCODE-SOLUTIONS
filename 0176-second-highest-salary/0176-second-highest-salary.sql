with cte as
    (select *, DENSE_RANK() over(ORDER by salary DESC)
    as r
    from employee)

select IFNULL((select salary from cte where r=2 limit 1),null) as SecondHighestSalary;