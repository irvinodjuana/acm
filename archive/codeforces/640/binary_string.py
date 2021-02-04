import sys

cases = int(sys.stdin.readline())

for _ in range(cases):
    n0, n1, n2 = tuple(map(int, sys.stdin.readline().strip().split()))
    l0 = "0" * (n0 + 1)
    l2 = "1" * (n2 + 1)
    if n1 % 2 == 1:
        l1 = "10" * (n1 // 2)
        print(l0 + l1 + l2)
    else:
        l1 = "10" * ((n1 - 1) // 2)
        if n0 != 0:
            print("1" + l0 + l1 + l2)
        elif n2 != 0:
            print(l0 + l1 + l2 + "0")
