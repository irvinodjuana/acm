import sys

cases = int(sys.stdin.readline())
soln = {1:1}

def collatz(n):
    if n not in soln:
        if n % 2 == 1:
            soln[n] = 1 + collatz(3*n+1)
        else:
            soln[n] = 1 + collatz(n // 2)
    return soln[n]

for _ in range(cases):
    i, j = map(int, sys.stdin.readline().split())
    max_len = 0
    for k in range(min(i,j), max(i,j)+1):
        max_len = max(max_len, collatz(k))
    print(i, j, max_len)
