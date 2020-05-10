import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    length = int(sys.stdin.readline())
    candies = list(map(int, sys.stdin.readline().strip().split()))
    i = 0
    j = length
    a = last = candies[0]
    b = 0
    moves = 1
    a_turn = False

    while True:
        if a_turn:
            count = 0
            while i < j - 1 and count <= last:
                i += 1
                count += candies[i]
            a += count
            last = count
            a_turn = False

        else:
            count = 0
            while j > i + 1 and count <= last:
                j -= 1
                count += candies[j]
            b += count
            last = count
            a_turn = True
        
        if count != 0:
            moves += 1
        if i >= j - 1:
            break

    print(moves, a, b)
    
