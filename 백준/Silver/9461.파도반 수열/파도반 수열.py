import sys

t = int(input())
mem = [0, 1, 1, 1] # 0 1 2 3
n = []

for i in range(t):
    n.append(int(input()))

maximum = max(n)

if maximum < 4:
    for i in n:
        print(mem[i])

    sys.exit(0)

for i in range(4, maximum + 1):
    mem.append(mem[i - 2] + mem[i - 3])

for i in n:
    print(mem[i])
    

