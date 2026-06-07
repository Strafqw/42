import ex0


def test_factory(factory: ex0.CreatureFactory) -> None:
    base = factory.create_base()
    evolved = factory.create_evolved()
    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())


def battle(f1: ex0.CreatureFactory, f2: ex0.CreatureFactory) -> None:
    poke1 = f1.create_base()
    poke2 = f2.create_base()
    print(poke1.describe())
    print(" vs.")
    print(poke2.describe())
    print(" fight!")
    print(poke1.attack())
    print(poke2.attack())


print("Testing factory")
test_factory(ex0.FlameFactory())
print()
print("Testing factory")
test_factory(ex0.AquaFactory())
print()
print("Testing battle")
battle(ex0.FlameFactory(), ex0.AquaFactory())
