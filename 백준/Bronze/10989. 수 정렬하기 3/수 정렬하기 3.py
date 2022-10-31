import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().rstrip())
counting_arr = [0 for _ in range(10000 + 1)]
for _ in range(N):
    counting_arr[int(input().rstrip())] += 1

for i in range(1, 10000 + 1):
    if counting_arr[i] > 0:
        for j in range(counting_arr[i]):
            print(f'{i}\n')


