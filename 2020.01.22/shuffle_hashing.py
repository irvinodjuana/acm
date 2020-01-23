import sys

# O(n): where n is length of s1, s2 (same length)
def are_anagrams(s1, s2):
    d1 = {}
    d2 = {}
    for l in s1:
        d1[l] = 1 + d1.get(l, 0)
    for l in s2:
        d2[l] = 1 + d2.get(l, 0)

    return d1 == d2
    

n = int(sys.stdin.readline())
pwords = []
hashes = []

for i in range(n):
    pwords.append(sys.stdin.readline().strip())
    hashes.append(sys.stdin.readline().strip())

for i in range(n):
    pword = pwords[i]
    hash = hashes[i]
    plen = len(pword)
    diff = len(hash) - plen + 1
    res = "NO"

    for j in range(diff):
        if are_anagrams(pword, hash[j:j+plen]):
            res = "YES"
            break
    
    print(res)

