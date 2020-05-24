import sys
import math

cases = int(sys.stdin.readline())

for _ in range(cases):
    ''' inputs '''
    # n = int(sys.stdin.readline())                         # single input
    n, k = map(int, sys.stdin.readline().split())         # two inputs
    # A = list(map(int, sys.stdin.readline().split()))      # list input
    '''code here'''

    res = None
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0 and (n // i) <= k:
            res = i
            break
    
    if not res:
        res = n
    
    print(res)
