import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals.groupby('name').filter(lambda x : x['weight'] >100).sort_values(by = ['weight'], ascending = False)[['name']]