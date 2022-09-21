from cs50 import get_float

# Cash.py

while True:
    # User Input Dollars
    change_dollar = get_float("Change owed: ")
    if change_dollar > 0:
        break
    else:
        continue
# Converting Input to cents
change_cents = change_dollar * 100

# Counting max number of quarter coins
max_quarter = change_cents // 25
change_cents %= 25

# Counting max number of dimes coins
max_dime = change_cents // 10
change_cents %= 10

# Counting max number of nickel coins
max_nickel = change_cents // 5
change_cents %= 5

# Counting the max numbber of penny coins
max_penny = change_cents

# Counting the max no. of coins by adding individuals
max_coins = max_quarter + max_dime + max_nickel + max_penny

# Printing Max Coins
print(f"{max_coins}")