import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    n = int(sys.stdin.readline())

    if n <= 3:
        print(-1)
    else:
        mid = [3, 1, 4, 2]
        evens = list(range(6, n+1, 2))[::-1]
        odds = list(range(5, n+1, 2))
        print(" ".join(map(str, evens + mid + odds)))