import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees.insert(2, "bonus", 2*employees["salary"])
    return employees
    
