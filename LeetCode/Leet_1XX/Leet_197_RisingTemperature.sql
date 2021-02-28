
SELECT a.Id FROM Weather AS a
JOIN Weather AS b
ON a.Temperature > b.Temperature
AND dateDiff(a.RecordDate,b.RecordDate) = 1;
