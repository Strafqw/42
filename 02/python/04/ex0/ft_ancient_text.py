import sys

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: ft_ancient_text.py <file>")
        sys.exit()
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        f = open(sys.argv[1])
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
    else:
        content = f.read()
        print("---")
        print(content)
        f.close()
        print("---")
        print(f"File '{sys.argv[1]}' closed.")
