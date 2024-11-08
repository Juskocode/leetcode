# Problem 2882: Drop Duplicate Rows

**Solved**

**Difficulty:** Easy

**Companies:** [Insert Company Names if applicable]

---

## Description

You are given a DataFrame called `customers`, which contains information about customers, including `customer_id`, `name`, and `email`. There are duplicate rows in the DataFrame based on the `email` column.

Your task is to remove these duplicate rows, keeping only the first occurrence of each unique email.

---

## Example

### Input

Suppose the `customers` DataFrame is structured as follows:

| customer_id | name       | email              |
|-------------|------------|--------------------|
| 1           | Alice      | alice@example.com  |
| 2           | Bob        | bob@example.com    |
| 3           | Charlie    | alice@example.com  |

### Output

| customer_id | name       | email              |
|-------------|------------|--------------------|
| 1           | Alice      | alice@example.com  |
| 2           | Bob        | bob@example.com    |

---

## Solution

To remove duplicate rows based on a specific column in a DataFrame, you can use the `drop_duplicates()` method in Pandas. The `subset` parameter specifies the column(s) to check for duplicates, and the `keep` parameter controls which occurrence to retain (default is `first`).

### Step-by-Step Guide

1. **Identify Duplicates:**
   - Use the `email` column to identify duplicate rows.

2. **Drop Duplicates:**
   - Use `drop_duplicates(subset=['email'], keep='first')` to remove duplicates, keeping only the first occurrence.

3. **Return the Result:**
   - The resulting DataFrame contains unique rows based on the `email` column.

### Implementation

```python
def drop_duplicate_customers(customers):
    # Remove duplicate rows based on the 'email' column
    customers = customers.drop_duplicates(subset=['email'], keep='first')
    return customers

# Example usage:
import pandas as pd

data = {
    'customer_id': [1, 2, 3],
    'name': ['Alice', 'Bob', 'Charlie'],
    'email': ['alice@example.com', 'bob@example.com', 'alice@example.com']
}
customers = pd.DataFrame(data)

result = drop_duplicate_customers(customers)
print(result)

