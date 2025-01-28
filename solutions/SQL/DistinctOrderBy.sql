SELECT
    distinct author_id as id
FROM
    views
WHERE
    author_id = viewer_id
ORDER BY
    id
