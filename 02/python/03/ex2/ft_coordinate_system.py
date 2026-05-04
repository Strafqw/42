import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        raw = input("enter coordinates as floats (x,y,z): ")
        parts = raw.split(',')
        if len(parts) != 3:
            print("Invalid syntax")
            continue
        try:
            coords = []
            for p in parts:
                coords.append(float(p))
        except ValueError as e:
            print(f"Error on parameter '{p}': {e}")
            continue
        return (coords[0], coords[1], coords[2])


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    p1 = get_player_pos()
    print(f"Got a first tuple: {p1}")
    print(f"It includes: X={p1[0]}, Y={p1[1]}, Z={p1[2]}")
    dist1 = math.sqrt(p1[0]**2 + p1[1]**2 + p1[2]**2)
    print(f"Distance to center: {round(dist1, 4)}")
    print()
    print("Get a second set of coordinates")
    p2 = get_player_pos()
    dist2 = math.sqrt((p2[0]-p1[0])**2 + (p2[1]-p1[1])**2 + (p2[2]-p1[2])**2)
    print(f"Distance between the 2 sets of coordinates: {round(dist2, 4)}")
