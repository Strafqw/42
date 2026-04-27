class GardenError(Exception):
    """Base error for garden problems."""
    def __init__(self, message: str = "Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    """Errors related to plants."""
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    """Errors related to watering."""
    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def check_water_level(level: int) -> None:
    if level < 10:
        raise WaterError("Not enough water in the tank!")


def check_plant(plant_name: str) -> None:
    if plant_name == "tomato":
        raise PlantError("The tomato plant is wilting!")


def test_garden_errors() -> None:
    print("=== Custom Garden Errors Demo ===")
    print()
    print("Testing PlantError...")
    try:
        check_plant("tomato")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()
    print("Testing WaterError...")
    try:
        check_water_level(5)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()
    print("Testing catching all garden errors...")
    try:
        check_plant("tomato")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        check_water_level(5)
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    print("All custom error types work correctly!")


if __name__ == "__main__":
    test_garden_errors()
