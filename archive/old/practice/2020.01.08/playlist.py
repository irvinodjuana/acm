import sys

params = [int(i) for i in sys.stdin.readline().split()]

n = params[0]
k = params[1]

if (k == 0):
    print(0)

songs = []
beauties = []

# O(n)
for i in range(n):
    params = [int(i) for i in sys.stdin.readline().split()]
    songs.append((params[0], params[1]))
    beauties.append(params[1])

# O(n log n)
songs.sort(key=lambda r: -1*r[0])           

output = 0

# O(k * n)
for b in beauties:
    curr_len = 0
    num = 0
    for s in songs:
        if num >= k:
            break
        else:
            if s[1] >= b:
                curr_len += s[0]
                num += 1

    if curr_len * b > output:
        output = curr_len * b

print(output)
