import sys
from collections import deque

cases = int(sys.stdin.readline())

for _ in range(cases):
    # code here
    n = int(sys.stdin.readline())
    a = [0] * n
    q = deque()
    q.append((0, n-1))

    while q:
        l, r = q.popleft()
        size = r - l + 1
        if size <= 0:
            continue
        elif size % 2 == 0:
            mid = (l + r - 1) // 2
            a[mid] = size
            q.append((mid+1, r))
            q.append((l, mid-1))
        else:
            mid = (l + r) // 2
            a[mid] = size
            q.append((l, mid-1))
            q.append((mid+1, r))
    
    indices = list(range(n))
    indices = sorted(indices, key=lambda i: a[i], reverse=True)
    j = 1
    for i in indices:
        a[i] = j
        j += 1
    
    print(" ".join(map(str, a)))
