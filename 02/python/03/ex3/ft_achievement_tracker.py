import random

ACHIEVEMENTS = [
    'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner',
    'Survivor', 'Master Explorer', 'Treasure Hunter', 'Unstoppable',
    'First Steps', 'Collector Supreme', 'Untouchable', 'Sharp Mind',
    'Boss Slayer', 'Hidden Path Finder',
]


def gen_player_achievements() -> set[str]:
    n = random.randint(5, 10)
    return set(random.sample(ACHIEVEMENTS, n))


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    print()
    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dilan = gen_player_achievements()
    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dilan: {dilan}")
    print()
    full = set(ACHIEVEMENTS)
    print(f"All distinct achievements: {alice.union(bob, charlie, dilan)}")
    print()
    print(f"Common achievements: {alice.intersection(bob, charlie, dilan)}")
    print()
    print(f"Only Alice has: {alice.difference(bob, charlie, dilan)}")
    print(f"Only Bob has: {bob.difference(alice, charlie, dilan)}")
    print(f"Only Charlie has: {charlie.difference(bob, alice, dilan)}")
    print(f"Only Dilan has: {dilan.difference(bob, charlie, alice)}")
    print()
    print(f"Alice is missing: {full.difference(alice)}")
    print(f"Bob is missing: {full.difference(bob)}")
    print(f"Charlie is missing: {full.difference(charlie)}")
    print(f"Dilan is missing: {full.difference(dilan)}")
