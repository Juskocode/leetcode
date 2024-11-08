# Problem 2881: Create a New Column

**Solved**

**Difficulty:** Easy

**Companies:** [Insert Company Names if applicable]

---

## Description

You are given a DataFrame called `employees`, which contains information about employees, including their `name` and `salary`. The company plans to provide its employees with a bonus, which will be double the value of their current salary.

Your task is to create a new column called `bonus` that contains the doubled values of the `salary` column.

---

## Example

### Input

Suppose the `employees` DataFrame is structured as follows:

| name       | salary |
|------------|--------|
| Alice      | 50000  |
| Bob        | 60000  |
| Charlie    | 55000  |

### Output

| name       | salary | bonus  |
|------------|--------|--------|
| Alice      | 50000  | 100000 |
| Bob        | 60000  | 120000 |
| Charlie    | 55000  | 110000 |

---

## Solution

To create a new column in the DataFrame, you can simply assign a new column and perform the desired operation. In this case, the new column `bonus` should be equal to `2 * salary`.

### Step-by-Step Guide

1. **Create the `bonus` Column:**
   - Multiply the `salary` column by 2 and assign the result to a new column called `bonus`.

2. **Display the Updated DataFrame:**
   - The DataFrame will now contain the new `bonus` column with doubled salary values.

### Implementation

```python
def create_bonus_column(employees):
    # Create the 'bonus' column by doubling the 'salary' column
    employees['bonus'] = employees['salary'] * 2
    return employees

# Example usage:
import pandas as pd

data = {
    'name': ['Alice', 'Bob', 'Charlie'],
    'salary': [50000, 60000, 55000]
}
employees = pd.DataFrame(data)

result = create_bonus_column(employees)
print(result)

