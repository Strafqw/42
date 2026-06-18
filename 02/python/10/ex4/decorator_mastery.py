import functools
import time
from collections.abc import Callable


def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Casting {func.__name__}...")
        start = time.perf_counter()
        result = func(*args, **kwargs)
        elapsed = time.perf_counter() - start
        print(f"Spell completed in {elapsed:.3f} seconds")
        return result

    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            power = kwargs.get("power")
            if power is None and args:
                power = args[-1]
            if not isinstance(power, int) or power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)

        return wrapper

    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(
                            "Spell failed, retrying... "
                            f"(attempt {attempt}/{max_attempts})"
                        )
            return (
                f"Spell casting failed after {max_attempts} attempts"
            )

        return wrapper

    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) >= 3 and all(
            char.isalpha() or char.isspace() for char in name
        )

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


def main() -> None:
    print("Testing spell timer...")

    @spell_timer
    def fireball() -> str:
        time.sleep(0.1)
        return "Fireball cast!"

    print(f"Result: {fireball()}")

    print("\nTesting power validator...")

    @power_validator(50)
    def lightning_bolt(target: str, power: int) -> str:
        return f"Lightning bolt zaps {target} for {power}"

    print(lightning_bolt("Troll", 80))
    print(lightning_bolt("Troll", 20))

    print("\nTesting retrying spell...")

    @retry_spell(3)
    def doomed_spell() -> str:
        raise ValueError("the spell fizzles")

    print(doomed_spell())

    @retry_spell(3)
    def lucky_spell() -> str:
        return "Waaaaaaagh spelled !"

    print(lucky_spell())

    print("\nTesting MageGuild...")
    print(MageGuild.validate_mage_name("Gandalf"))
    print(MageGuild.validate_mage_name("Xx"))
    guild = MageGuild()
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Spark", 5))


if __name__ == "__main__":
    main()
