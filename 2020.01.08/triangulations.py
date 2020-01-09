import sys

n = int(sys.stdin.readline())
value = 0

for i in range(2, n):
    value += (i * (i+1))

print(value)