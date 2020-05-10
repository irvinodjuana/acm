import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    n, k = sys.stdin.readline().strip().split()
    n, k = int(n), int(k)
    if k % (n-1) == 0:
        print(n * (k // (n-1)) + k % (n-1) - 1)
    else:
        print(n * (k // (n-1)) + k % (n-1))