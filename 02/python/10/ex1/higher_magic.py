from collections.abc import Callable


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    if not (callable(spell1) and callable(spell2)):
        raise TypeError("spell_combiner expects two callables")

    def combined(target: str, power: int) -> tuple:
        return spell1(target, power), spell2(target, power)

    return combined


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)

    return amplified


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def guarded(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"

    return guarded


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence(target: str, power: int) -> list:
        return [spell(target, power) for spell in spells]

    return sequence


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def main() -> None:
    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    hit, mend = combined("Dragon", 30)
    print(f"Combined spell result: {hit} | {mend}")

    print("\nTesting power amplifier...")
    mega = power_amplifier(fireball, 3)
    print(f"Original: {fireball('Goblin', 10)}")
    print(f"Amplified: {mega('Goblin', 10)}")

    print("\nTesting conditional caster...")
    strong_only = conditional_caster(
        lambda target, power: power >= 50, fireball
    )
    print(strong_only("Slime", 20))
    print(strong_only("Slime", 80))

    print("\nTesting spell sequence...")
    barrage = spell_sequence([fireball, heal, fireball])
    for line in barrage("Orc", 15):
        print(line)


if __name__ == "__main__":
    main()
