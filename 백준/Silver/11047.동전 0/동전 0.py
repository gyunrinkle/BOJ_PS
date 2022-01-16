import sys
    
n, k = map(int, sys.stdin.readline().split())
coin = []

for i in range(n):
    tmp = int(sys.stdin.readline())

    if tmp <= k:
        coin.append(tmp)
    else:
        continue

cnt = 0
i = len(coin) - 1

while k > 0:
    cnt += (k // coin[i])
    k %= coin[i]
    i -= 1

sys.stdout.write(str(cnt))
