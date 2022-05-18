import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

n = int(input().rstrip())
lis = [1] * n
lines = [tuple(map(int, input().rstrip().split())) for _ in range(n)]
lines.sort()

for i in range(n):
    tmp = [lis[k] for k in range(i) if lines[k][1] < lines[i][1]]
    lis[i] = max(tmp) + 1 if tmp else 1

lis.sort()
print(n - lis[n - 1])


