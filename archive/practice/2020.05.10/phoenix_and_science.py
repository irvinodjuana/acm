import sys

def find(mass, num, goal, path):
    if mass > goal:
        return False, None
    if mass == goal:
        return True, path
    
    for split in range(num, -1, -1):
        found, soln = find(mass + num + split, num + split, goal, path + [split])
        if found:
            return True, soln

    return False, None

cases = int(sys.stdin.readline())

for _ in range(cases):
    n = int(sys.stdin.readline())
    _, path = find(1, 1, n, [])
    print(len(path))
    print(*path)

