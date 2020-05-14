import sys

num_tests = int(sys.stdin.readline())
results = []

for i in range(num_tests):
    length = int(sys.stdin.readline())
    string = sys.stdin.readline().strip()
    
    count = 0
    for i in range(length):
        if string[i] == '<' and string[-1 * (i+1)] == '>':
            count += 1
        else:
            break
    results.append(count)

for r in results:
    print(r)
