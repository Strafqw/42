import random


if __name__ == "__main__":
    print("=== Game Data Alchemist ===")
    players = [
        "Alice", "bob", "Charlie", "dylan", "Emma",
        "Gregory", "john", "kevin", "Liam",
    ]
    print()
    print(f"Initial list of players: {players}")
    all_caps = [n.capitalize() for n in players]
    print(f"New list with all names capitalized: {all_caps}")
    only_caps = [n for n in players if n[0].isupper()]
    print(f"New list of capitalized names only: {only_caps}")
    scores = {n: random.randint(0, 1000) for n in all_caps}
    print(f"Score dict: {scores}")
    avg = round(sum(scores.values()) / len(scores), 2)
    print(f"Score average is {avg}")
    high_scores = {n: scores[n] for n in scores if scores[n] > avg}
    print(f"High scores: {high_scores}")
