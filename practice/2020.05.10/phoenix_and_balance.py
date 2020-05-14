import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    n = int(sys.stdin.readline())
    print(2**(n//2+1) - 2)
