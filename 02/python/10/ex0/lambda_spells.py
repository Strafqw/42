def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda a: a["power"], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda m: m["power"] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda s: f"* {s} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    if not mages:
        return {"max_power": 0, "min_power": 0, "avg_power": 0.0}
    total = sum(map(lambda m: m["power"], mages))
    return {
        "max_power": max(mages, key=lambda m: m["power"])["power"],
        "min_power": min(mages, key=lambda m: m["power"])["power"],
        "avg_power": round(total / len(mages), 2),
    }


def main() -> None:
    artifacts = [
        {"name": "Crystal Orb", "power": 85, "type": "orb"},
        {"name": "Fire Staff", "power": 92, "type": "staff"},
        {"name": "Ice Wand", "power": 78, "type": "wand"},
    ]
    mages = [
        {"name": "Alex", "power": 70, "element": "fire"},
        {"name": "Jordan", "power": 45, "element": "water"},
        {"name": "Riley", "power": 95, "element": "air"},
    ]
    spells = ["fireball", "heal", "shield"]

    print("Testing artifact sorter...")
    ordered = artifact_sorter(artifacts)
    first, second = ordered[0], ordered[1]
    print(
        f"{first['name']} ({first['power']} power) comes before "
        f"{second['name']} ({second['power']} power)"
    )

    print("\nTesting spell transformer...")
    print(" ".join(spell_transformer(spells)))

    print("\nTesting power filter...")
    strong = power_filter(mages, 60)
    print(f"{len(strong)} mages have power >= 60")

    print("\nTesting mage stats...")
    print(mage_stats(mages))


if __name__ == "__main__":
    main()
