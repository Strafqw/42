from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.capabilities import HealCapability, TransformCapability


class InvalidStratError(Exception):
    pass


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, creature: Creature) -> None: ...

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool: ...


class NormalStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> None:
        print(creature.attack())


class AggressiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStratError(
                f"Invalid Creature '{creature.name}' for this aggressive "
                f"strategy")
        assert isinstance(creature, TransformCapability)
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, creature: Creature):
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStratError(
                f"Invalid Creature '{creature.name}' for this defensive "
                f"strategy")
        assert isinstance(creature, HealCapability)
        print(creature.attack())
        print(creature.heal())
