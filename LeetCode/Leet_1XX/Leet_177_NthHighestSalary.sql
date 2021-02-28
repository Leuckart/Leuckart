
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN
    (     
        SELECT IF(count<N,NULL,min) 
        FROM
        (
            SELECT MIN(Salary) AS min, COUNT(1) AS count
            FROM
            (
                SELECT DISTINCT Salary
                FROM Employee
                ORDER BY Salary DESC LIMIT N
            )
            AS a
        )
        as b
    );
END
