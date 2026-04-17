class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")

def garden_data():
    p1 = Plant("Rose", 13, 20)
    p2 = Plant("Tulip", 14, 21)
    p3 = Plant("Cactus", 15, 22)
    print("=== Garden Plant Registry ===")
    p1.show()
    p2.show()
    p3.show()
    
if __name__ == "__main__":
    garden_data()