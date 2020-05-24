import sys
import math

cases = int(sys.stdin.readline())

for _ in range(cases):
    ''' inputs '''
    # n = int(sys.stdin.readline())                         # single input
    n, m, a, b = map(int, sys.stdin.readline().split())         # two inputs
    # A = list(map(int, sys.stdin.readline().split()))      # list input
    '''code here'''
    
    if (n * a != m * b):
        print("NO")
        continue
    
    if (b > int(math.sqrt(n))):
        b = n // b
        a = m // a
        swap = True

    M = [["0" if not swap else "1" for _ in range(m)] for _ in range(n)]
    i = 0
    while i < n:
        j = i % (n // b)
        while j < m:
            M[i][j] = "1" if not swap else "0"
            j += (m // a)
        i += 1
    
    print("YES")
    for m in M:
        print("".join(m))



    