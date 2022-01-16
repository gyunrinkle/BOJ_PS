import sys

n = int(sys.stdin.readline())
counting = [0 for _ in range(10000 + 1)]


for i in range(n):

    counting[int(sys.stdin.readline())] += 1

for i in range(1, 10000 + 1):
    if counting[i] != 0:
        for j in range(counting[i]):
            sys.stdout.write(str(i) + '\n')
