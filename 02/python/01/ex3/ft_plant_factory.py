class Plant:
    def __init__(self, name: str, height: float, days: int) -> None:
        self.name = name
        self.height = height
        self.days = days

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self) -> None:
        self.height = round(self.height + 0.8, 1)

    def age(self) -> None:
        self.days += 1


def plant_factory() -> None:
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 25.0, 30)
    print("Created: ", end="")
    rose.show()
    oak = Plant("Oak", 200.0, 365)
    print("Created: ", end="")
    oak.show()
    cactus = Plant("Cactus", 5.0, 90)
    print("Created: ", end="")
    cactus.show()
    sunflower = Plant("Sunflower", 80.0, 45)
    print("Created: ", end="")
    sunflower.show()
    fern = Plant("Fern", 15.0, 120)
    print("Created: ", end="")
    fern.show()


if __name__ == "__main__":
    plant_factory()
