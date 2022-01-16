import sys

n = int(sys.stdin.readline())
lst = []

for i in range(n):
    lst.append(int(sys.stdin.readline()))

for i in range(1, len(lst)):
    key = lst[i]
    j = i - 1

    while key < lst[j] and j >= 0:
        lst[j+1] = lst[j]
        j -= 1
    
    lst[j+1] = key

for i in range(len(lst)):
    print(lst[i])

