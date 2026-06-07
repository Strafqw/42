import ex0
import ex1
from ex0.factory import CreatureFactory
from ex2.strategies import (
    BattleStrategy,
    NormalStrategy,
    AggressiveStrategy,
    DefensiveStrategy,
    InvalidStratError,
)


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print()
    try:
        for i in range(len(opponents)):
            for j in range(i + 1, len(opponents)):
                factory_a, strategy_a = opponents[i]
                factory_b, strategy_b = opponents[j]
                creature_a = factory_a.create_base()
                creature_b = factory_b.create_base()
                print("* Battle *")
                print(creature_a.describe())
                print(" vs.")
                print(creature_b.describe())
                print(" now fight!")
                strategy_a.act(creature_a)
                strategy_b.act(creature_b)
                print()
    except InvalidStratError as e:
        print(f"Battle error, aborting tournament: {e}")


print("Tournament 0 (basic)")
print("[ (Flameling+Normal), (Healing+Defensive) ]")
battle([
    (ex0.FlameFactory(), NormalStrategy()),
    (ex1.HealingFactory(), DefensiveStrategy()),
])
print()
print("Tournament 1 (error)")
print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
battle([
    (ex0.FlameFactory(), AggressiveStrategy()),
    (ex1.HealingFactory(), DefensiveStrategy())
])
print()
print("Tournament 2 (multiple)")
print("[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
battle([
    (ex0.AquaFactory(), NormalStrategy()),
    (ex1.HealingFactory(), DefensiveStrategy()),
    (ex1.TransformFactory(), AggressiveStrategy())
])
