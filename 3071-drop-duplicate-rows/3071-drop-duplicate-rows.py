import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    unique = set()
    dup = []
    for id_, email in zip(customers['customer_id'], customers['email']):
        if email in unique:
            dup.append(id_ - 1)
        unique.add(email)

    customers = customers.drop(dup)
    return customers

    