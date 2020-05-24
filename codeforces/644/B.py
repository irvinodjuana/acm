import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    ''' inputs '''
    n = int(sys.stdin.readline())                         # single input
    # n, m = map(int, sys.stdin.readline().split())         # two inputs
    A = list(map(int, sys.stdin.readline().split()))      # list input
    '''code here'''

    A = sorted(A)
    min_diff = float('inf')
    for i in range(len(A)-1):
        min_diff = min(min_diff, abs(A[i+1] - A[i]))
    print(min_diff)

