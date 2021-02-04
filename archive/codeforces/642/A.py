import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    # code here
    n, m = map(int, sys.stdin.readline().split())
    if n <= 3:
        print((n-1) * m)
    else:
        print(2*m)
