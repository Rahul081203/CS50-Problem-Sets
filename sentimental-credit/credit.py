from cs50 import get_int

# Credit.py

# User Input Card Number
card = get_int("Number: ")

copy = []
card_copy = card
while card_copy >= 1:
    l_num = card_copy % 10
    card_copy //= 10
    # Copying Card Number to List copy
    copy += [l_num]

copy.reverse()
#  Check Luhn's Algorithm
sum = 0
# Iterating from second to last digit reversely each other element
for i in copy[-2:: -2]:
    # Adding to sum the sum of each and every digit
    element = i * 2
    if (element > 9):
        while element >= 1:
            mod = element % 10
            sum += mod
            element //= 10
    else:
        sum += element
# Iterating the card number from the last to each and every digit
for i in copy[-1:: -2]:
    sum += i

# Checking if the last digit is zero
if sum % 10 == 0:
    valid = True
else:
    valid = False

# Checking Card Type if card number is valid according to Luhn's Algorithm

if valid == True:
    # Printing the valid card type
    if len(copy) == 15 and copy[0] == 3 and (copy[1] in [4, 7]):
        print("AMEX")
    elif len(copy) == 16 and copy[0] == 5 and (copy[1] in range(1, 6)):
        print("MASTERCARD")
    elif (len(copy) in [13, 16]) and copy[0] == 4:
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")