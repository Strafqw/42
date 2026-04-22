class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        if height < 0:
            print(f"{name}: Error, height can't be negative")
            self._height = 0.0
        else:
            self._height = height
        if days < 0:
            print(f"{name}: Error, age can't be negative")
            self._days = 0
        else:
            self._days = days

    def show(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._days} days old")

    def grow(self) -> None:
        self._height = round(self._height + 0.8, 1)

    def age(self) -> None:
        self._days += 1

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days

    def set_height(self, new_height: float) -> None:
        if (new_height < 0):
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new_height
            print(f"Height updated: {self._height}cm")

    def set_age(self, new_age: int) -> None:
        if (new_age < 0):
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._days = new_age
            print(f"Age updated: {self._days} days")


class Flower(Plant):
    def __init__(self, name: str, height: float, days: int, color: str,) -> None:
        super().__init__(name, height, days)
        self.color = color
        self._bloomed = False

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self._bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")

    def bloom(self) -> None:
        self._bloomed = True


class Tree(Plant):
    def __init__(self, name: str, height: float, days: int, trunk_diameter: float) -> None:
        super().__init__(name, height, days)
        self.trunk_diameter = trunk_diameter
    
    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")
    
    def produce_shade(self) -> None:
        print(f"Tree {self.name} now produces a shade of {self._height}cm long and {self.trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, days: int, harvest_season: str, nutritional_value: int):
        super().__init__(name, height, days)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")



print("=== Garden Plant Types ===")
print("=== Flower")
rose = Flower("Rose", 15.0, 10, "red")
rose.show()
print("[asking rose to bloom]")
rose.bloom()
rose.show()
print()
print("=== Tree")
oak = Tree("Oak", 200.0, 365, 5.0)
oak.show()
print("[asking the oak to produce shade]")
oak.produce_shade()
