import numpy as np
from random import randint

n = 5
m = 3
f = open("in", "w+")
f.write(str(n) + " " + str(m) + "\n")
for i in range (n):
    for j in range (m):
        num = randint(1, 5)
        if num % 2 == 0:
            f.write("#")
        else:
            f.write(".")
    f.write("\n")

tiros = randint(1, n * m)
f.write(str(tiros) + "\n")
for i in range(tiros):
    row = randint(1, n)
    col = randint(1, m)
    f.write(str(row) + " " + str(col) + "\n")
