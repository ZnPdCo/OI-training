import numpy
import random
n = 100
m = 1000000
cnt = 0
print(n, m)
for i in range(n):
    a = random.randint(-1e100, 1e100)
    print(a, end=' ')
    cnt += a
print(-cnt)
