import ex1
from ex1.capabilities import HealCapability, TransformCapability


def test_healing(factory: ex1.HealingFactory) -> None:
    base = factory.create_base()
    evolved = factory.create_evolved()
    assert isinstance(base, HealCapability)
    assert isinstance(evolved, HealCapability)
    print("Testing Creature with healing capability")
    print(" base:")
    print(base.describe())
    print(base.attack())
    print(base.heal())
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.heal())
    print()


def test_transform(factory: ex1.TransformFactory) -> None:
    base = factory.create_base()
    evolved = factory.create_evolved()
    assert isinstance(base, TransformCapability)
    assert isinstance(evolved, TransformCapability)
    print("Testing Creature with transform capability")
    print(" base:")
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())
    print(" evolved:")
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())


test_healing(ex1.HealingFactory())
test_transform(ex1.TransformFactory())
