select Max(salary) as SecondHighestSalary
from employee
where employee.salary not in (
    select max(salary)
    from employee
    # group by salary
)


