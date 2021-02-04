import sys

n = int(sys.stdin.readline())

for i in range(n):
    num = sys.stdin.readline().strip()
    tens = 10 ** (len(num) - 1)
    digits = []
    count = 0

    for digit in num:
        if digit != "0":
            digits.append(str(int(int(digit) * tens)))
            count += 1
        tens /= 10
    
    print(count)
    print(" ".join(digits))




    
