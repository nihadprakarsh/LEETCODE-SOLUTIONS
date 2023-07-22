SELECT
    employee_id,
    (
        IF(
            mod(employee_id, 2) = 1 AND name NOT LIKE 'M%',
            salary,
            0
        )
    ) AS bonus
from Employees
order by employee_id asc;

