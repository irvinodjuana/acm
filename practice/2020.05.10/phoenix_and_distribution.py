import sys

# INCOMPLETE

cases = int(sys.stdin.readline())

for _ in range(cases):
    n, k = map(int, sys.stdin.readline().split())
    s = sys.stdin.readline()
    letters = sorted(set(s))
    add = True
    count = defaultdict(int)
    least = []

    for i in range(n):
        count[s[i]] += 1
    
    for l in letters:
        if not add:
            least.append(l)
            break

        c = count[l]
        least.append(l * (c // k))
        add = (c % k == 0)

