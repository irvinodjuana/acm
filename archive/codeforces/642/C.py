import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    # code here
    n = int(sys.stdin.readline())
    res = 0
    j = 0
    for i in range(1, n+1, 2):
        res += j * (4*i-4)
        j += 1
    print(res)
