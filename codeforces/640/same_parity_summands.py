import sys

n = int(sys.stdin.readline())

for _ in range(n):
    n, k = sys.stdin.readline().strip().split()
    n, k = int(n), int(k)

    if n % 2 == 0:
        # even
        if n < k or (k % 2 == 1 and n < 2 * k):
            print("NO")
        else:
            print("YES")
            if k % 2 == 0:
                digits = ["1"] * (k-1) + [str(n - (k - 1))]
            else:
                digits = ["2"] * (k-1) + [str(n - 2 * (k-1))]
            print(" ".join(digits))
    else:
        # odd
        if k % 2 == 0 or k > n:
            print("NO")
        else:
            print("YES")
            digits = ["1"] * (k-1) + [str(n - (k - 1))]
            print(" ".join(digits))
