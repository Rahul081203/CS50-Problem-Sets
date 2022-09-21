from cs50 import get_int

# Mario-Less.py

# Checking Condition
while True:
    height = get_int("Height: ")
    if height in range(1,9):
        break
    else:
        continue
# Looping for Pyramid
for i in range(1, height + 1):
    # Printing Trailing Spaces
    print(" " * (height - i), end="")
    # Printing Hashes
    print("#" * i)