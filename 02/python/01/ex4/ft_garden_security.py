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


def garden_security() -> None:
    rose = Plant("Rose", 15.0, 10)
    print("Created: ", end="")
    rose.show()
    print()
    rose.set_height(25.0)
    rose.set_age(30)
    print()
    rose.set_height(-10)
    rose.set_age(-20)
    print()
    print("Current state: ", end="")
    rose.show()


if __name__ == "__main__":
    garden_security()
