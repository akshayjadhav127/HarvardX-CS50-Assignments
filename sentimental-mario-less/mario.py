# TODO

from cs50 import get_int

while True:

    # input height
    n = get_int("Height: ")
    # upto 9 height
    if n > 0 and n < 9:
        break
for i in range(0, n, 1):
    for j in range(0, n, 1):
        if (i + j < n - 1):
            print(" ", end="")
        else:
            print("#", end="")
    print()