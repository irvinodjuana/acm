import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    ''' inputs '''
    # n = int(sys.stdin.readline())                         # single input
    a, b = map(int, sys.stdin.readline().split())         # two inputs
    # A = list(map(int, sys.stdin.readline().split()))      # list input
    '''code here'''

    small = min(a, b)
    large = max(a, b)

    if 2 * small > large:
        print((2*small) **2)
    else:
        print(large**2)

    

