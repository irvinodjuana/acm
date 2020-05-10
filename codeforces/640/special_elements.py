import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    length = int(sys.stdin.readline())
    elems = list(map(int, sys.stdin.readline().strip().split()))

    sums = set()

    for i in range(length):
        sum = elems[i]
        for j in range(i+1, length):
            sum += elems[j]
            sums.add(sum)
    
    count = 0

    for e in elems:
        if e in sums:
            count += 1
    
    print(count)
