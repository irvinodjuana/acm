import sys
from collections import deque

n = int(sys.stdin.readline())
a_list = []
b_list = []

for i in range(n):
    w = sys.stdin.readline().strip().split()
    a_list.append(w[0])
    b_list.append(w[1])


