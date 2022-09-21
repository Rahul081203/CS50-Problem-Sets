from cs50 import get_int

# Mario- More.py

# Checking Condition
while True:
    # Getting User Input
    height = get_int("Height: ")
    if height in range(1, 9):
        break
    else:
        continue

# Looping For Pyramid
for i in range(1, height + 1):
    # Printing Trailing Spaces
    print(" " * (height - i), end="")
    # Printing First Pyramid Hashes
    print("#" * i, end="")
    # Printing Gap between two pyramids
    print("  ", end="")
    # Printing Second Pyramid Hashes
    print("#" * i)