import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    n, k = map(int, sys.stdin.readline().split())
    nums = map(int, sys.stdin.readline().split())
    unique = set(nums)

    if len(unique) > k:
        print(-1)
        continue

    out = list(unique)
    out += [out[0]] * (k - len(out))
    out *= n
    print(len(out))
    print(" ".join(map(str, out)))