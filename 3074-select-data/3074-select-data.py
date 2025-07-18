import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students.groupby('student_id').filter(lambda x : x['student_id'] == 101)[['name', 'age']]