import sys

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: ft_archive_creation.py <file>")
        sys.exit()
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        f = open(sys.argv[1])
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
    else:
        content = f.read()
        print("---")
        print()
        print(content)
        f.close()
        print("---")
        print(f"File '{sys.argv[1]}' closed.")
        print()
        print("Transform data:")
        print("---")
        print()
        content = content.replace("\n", "#\n")
        print(content)
        print("---")
        filename = input("Enter new file name (or empty): ")
        if not filename:
            print("Not saving data.")
        else:
            print(f"Saving data to '{filename}'")
            try:
                file = open(filename, 'w')
                file.write(content)
                file.close()
                print(f"Data saved in file '{filename}'.")
            except OSError as e:
                print(f"Error opening file '{filename}': {e}")
                print("Data not saved.")
