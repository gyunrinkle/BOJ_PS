import sys
n = int(input())
mem = [0, 1, 2, 3]

if n > 3:
    for i in range(4, n + 1):
        mem.append(mem[i - 1] + mem[i -2])
        mem[i] %= 15746
    print(mem[n])
    sys.exit(0)

print(mem[n])


    