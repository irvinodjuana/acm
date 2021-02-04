import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    # code here
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    ans = sum(sorted(sorted(a) + sorted(b)[n-k:])[k:])
    print(ans)
