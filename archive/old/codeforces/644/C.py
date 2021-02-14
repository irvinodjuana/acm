import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    ''' inputs '''
    n = int(sys.stdin.readline())                         # single input
    # n, m = map(int, sys.stdin.readline().split())         # two inputs
    A = list(map(int, sys.stdin.readline().split()))      # list input
    '''code here'''

    adjacent = False
    count_even = 0
    A = sorted(A)
    for i in range(n):
        if i > 0 and (A[i] - A[i-1] == 1):
            adjacent = True
        if A[i] % 2 == 0:
            count_even += 1
    
    print("YES" if (adjacent or count_even % 2 == 0) else "NO")
