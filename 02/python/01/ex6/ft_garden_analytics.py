class Plant:
    class _Stats:
        def __init__(self) -> None:
            self._grow_count = 0
            self._age_count = 0
            self._show_count = 0

        def display(self) -> None:
            print(
                f"Stats: {self._grow_count} grow, "
                f"{self._age_count} age, "
                f"{self._show_count} show"
            )

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
        self._stats = self._Stats()

    def show(self) -> None:
        print(f"{self.name}: {self._height}cm, {self._days} days old")
        self._stats._show_count += 1

    def grow(self) -> None:
        self._height = round(self._height + 0.8, 1)
        self._stats._grow_count += 1

    def age(self) -> None:
        self._days += 1
        self._stats._age_count += 1

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days

    def set_height(self, new_height: float) -> None:
        if new_height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new_height
            print(f"Height updated: {self._height}cm")

    def set_age(self, new_age: int) -> None:
        if new_age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._days = new_age
            print(f"Age updated: {self._days} days")

    @staticmethod
    def is_older_than_year(days: int) -> bool:
        return days > 365

    @classmethod
    def create_anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    def __init__(
        self, name: str, height: float, days: int, color: str
    ) -> None:
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
    class _TreeStats(Plant._Stats):
        def __init__(self) -> None:
            super().__init__()
            self._shade_count = 0

        def display(self) -> None:
            super().display()
            print(f" {self._shade_count} shade")

    def __init__(
        self, name: str, height: float, days: int, trunk_diameter: float
    ) -> None:
        super().__init__(name, height, days)
        self.trunk_diameter = trunk_diameter
        self._stats = self._TreeStats()

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self._height}cm long and {self.trunk_diameter}cm wide."
        )
        self._stats._shade_count += 1


class Vegetable(Plant):
    def __init__(
        self, name: str, height: float, days: int, harvest_season: str
    ) -> None:
        super().__init__(name, height, days)
        self.nutritional_value = 0
        self.harvest_season = harvest_season

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow(self) -> None:
        self._height = round(self._height + 2.1, 1)
        self.nutritional_value += 1

    def age(self) -> None:
        super().age()


class Seed(Flower):
    def __init__(
        self, name: str, height: float, days: int, color: str
    ) -> None:
        super().__init__(name, height, days, color)
        self.seeds = 0

    def bloom(self) -> None:
        super().bloom()
        self.seeds = 42

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seeds}")


def display_stats(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant._stats.display()


def garden_analytics() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    display_stats(rose)
    print("[asking rose to grow and bloom]")
    rose.grow()
    rose.bloom()
    rose.show()
    display_stats(rose)
    print()
    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    display_stats(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    display_stats(oak)
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.bloom()
    sunflower.age()
    sunflower.show()
    display_stats(sunflower)
    print()
    print("=== Anonymous")
    mystery = Plant.create_anonymous()
    mystery.show()
    display_stats(mystery)


if __name__ == "__main__":
    garden_analytics()
