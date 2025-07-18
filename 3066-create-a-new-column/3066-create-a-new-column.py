import pandas as pd

def createBonusColumn(df: pd.DataFrame) -> pd.DataFrame:
    df['bonus'] = df['salary']*2
    return df