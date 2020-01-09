import sys

num_pages = int(sys.stdin.readline())
pages = [int(i) for i in sys.stdin.readline().split()]

page_set = set()
count = 0

for i, page in enumerate(pages):
    page_set.add(page)
    if i + 1 in page_set:
        page_set.remove(i + 1)
    if len(page_set) == 0:
        count += 1

print(count)