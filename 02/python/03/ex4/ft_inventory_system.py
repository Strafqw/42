import sys


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 program.py <key>:<value> ... <key>:<value>")
    inventory: dict[str, int] = {}
    for arg in sys.argv[1:]:
        parts = arg.split(':')
        if len(parts) != 2:
            print(f"Error - invalid parameter '{arg}'")
            print("Both parameters must be separated only by ':'")
            continue
        name, qty_str = parts[0], parts[1]
        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue
        try:
            qty = int(qty_str)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
            continue
        if qty <= 0:
            print(f"Quantity for {name} must be positive, got {qty}")
            continue
        inventory[name] = qty
    if len(inventory) > 0:
        print("=== Inventory System analysis ===")
        print(f"Got inventory: {inventory}")
        print(f"Item list: {list(inventory.keys())}")
        total = sum(inventory.values())
        print(f"Total quantity of the {len(inventory)} items: {total}")
        for key in inventory.keys():
            pct = round(inventory[key] / total * 100, 1)
            print(f"Item {key} represents {pct}%")
        keys_list = list(inventory.keys())
        most_key = keys_list[0]
        least_key = keys_list[0]
        for key in inventory.keys():
            if inventory[key] > inventory[most_key]:
                most_key = key
            if inventory[key] < inventory[least_key]:
                least_key = key
        mq = inventory[most_key]
        lq = inventory[least_key]
        print(f"Item most abundant: {most_key} with quantity {mq}")
        print(f"Item least abundant: {least_key} with quantity {lq}")
        inventory.update({'magic_item': 1})
        print(f"Updated inventory: {inventory}")
