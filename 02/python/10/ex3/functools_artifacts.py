import functools
import operator
from collections.abc import Callable
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    operations = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": lambda a, b: a if a > b else b,
        "min": lambda a, b: a if a < b else b,
    }
    if operation not in operations:
        raise ValueError(f"Unknown operation: {operation}")
    return functools.reduce(operations[operation], spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {
        "fire": functools.partial(base_enchantment, 50, "Fire"),
        "ice": functools.partial(base_enchantment, 50, "Ice"),
        "lightning": functools.partial(base_enchantment, 50, "Lightning"),
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def dispatch(spell: Any) -> str:
        return "Unknown spell type"

    @dispatch.register
    def _(spell: int) -> str:
        return f"{spell} damage"

    @dispatch.register
    def _(spell: str) -> str:
        return spell

    @dispatch.register
    def _(spell: list) -> str:
        return f"{len(spell)} spells"

    return dispatch


def base_enchantment(power: int, element: str, target: str) -> str:
    return f"{element} enchantment ({power}) on {target}"


def main() -> None:
    print("Testing spell reducer...")
    powers = [10, 20, 30, 40]
    print(f"Sum: {spell_reducer(powers, 'add')}")
    print(f"Product: {spell_reducer(powers, 'multiply')}")
    print(f"Max: {spell_reducer(powers, 'max')}")
    try:
        spell_reducer(powers, "divide")
    except ValueError as error:
        print(f"Handled error: {error}")

    print("\nTesting partial enchanter...")
    enchanters = partial_enchanter(base_enchantment)
    print(enchanters["fire"]("Sword"))

    print("\nTesting memoized fibonacci...")
    for index in (0, 1, 10, 15):
        print(f"Fib({index}): {memoized_fibonacci(index)}")
    print(f"Cache: {memoized_fibonacci.cache_info()}")

    print("\nTesting spell dispatcher...")
    cast = spell_dispatcher()
    print(f"Damage spell: {cast(42)}")
    print(f"Enchantment: {cast('fireball')}")
    print(f"Multi-cast: {cast(['a', 'b', 'c'])}")
    print(cast(3.14))


if __name__ == "__main__":
    main()
