SELECT COALESCE(
        (select distinct(salary)
        from employee
        where salary is not null
        order by salary DESC
        limit 1,1
    ),NULL
) as SecondHighestSalary;