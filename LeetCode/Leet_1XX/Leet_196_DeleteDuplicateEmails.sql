
DELETE FROM Person
WHERE id NOT IN
(
    SELECT need.id
    FROM
    (
        SELECT min(Id) AS id
        FROM Person
        GROUP BY Email
    )
    AS need
);
