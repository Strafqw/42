from typing import Generator
import random


def gen_event() -> Generator[tuple[str, str], None, None]:
    names = ["alice", "bob", "dilan", "charlie"]
    actions = ["eat", "sleep", "run", "grab", "move", "67"]
    while True:
        yield (random.choice(names), random.choice(actions))


def consume_event(
    events: list[tuple[str, str]]
) -> Generator[tuple[str, str], None, None]:
    while len(events) > 0:
        idx = random.randrange(len(events))
        ev = events.pop(idx)
        yield ev


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    g = gen_event()
    for i in range(1000):
        name, action = next(g)
        print(f"Event {i}: Player {name} did action {action}")
    ten_events = []
    for _ in range(10):
        ten_events.append(next(g))
    print(f"Built list of 10 events: {ten_events}")
    for event in consume_event(ten_events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {ten_events}")
