import sys

S = sys.stdin.readline().strip()
T = sys.stdin.readline().strip()
res = len(S) > 0 and len(S) <= 10 and len(T) == len(S) + 1 and S == T[:-1]

print("Yes" if res else "No")