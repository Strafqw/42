from elements import create_fire
from .. import elements, potions


def lead_to_gold() -> str:
    return (
        f"Recipe transmuting Lead to Gold: "
        f"brew '{elements.create_air()}' "
        f"and '{potions.strength_potion()}' "
        f"mixed with '{create_fire()}'")
