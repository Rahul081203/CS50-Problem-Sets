num = 1234567890123456
copy = num
l = []
while copy >= 1:
    l_num = copy % 10
    copy //= 10
    l += [l_num]
l.reverse()
print(f"List is {l}")