import sys

N, K = list(map(int, sys.stdin.readline().split()))
A = [None] + list(map(int, sys.stdin.readline().split()))

dist = [None, 0] + [None] * (N-1)
cycle_len = None
i = 0
town = 1

while True:
    next_town = A[town]
    if dist[next_town] is None:
        dist[next_town] = i+1
    elif cycle_len is None:
        cycle_len = i + 1 - dist[next_town]
        K = K % cycle_len
    
    if K <= 0:
        break
    
    town = next_town
    i += 1
    K -= 1

print(town)