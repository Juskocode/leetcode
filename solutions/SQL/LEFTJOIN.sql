SELECT
    eu.unique_id as unique_id, e.name as name
FROM
    employees e
LEFT JOIN
    employeeUNI eu on e.id = eu.id 
