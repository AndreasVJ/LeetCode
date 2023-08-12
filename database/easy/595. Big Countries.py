import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world[(world["area"] >= 3e6) | (world["population"] >= 2.5e7)][["name", "population", "area"]]