X = int(input())
MAX = 10 ** 6
dp = [-1] * (MAX + 1)
dp[1] = 0
dp[2] = 1
dp[3] = 1

for i in range(1, X + 1):
	if dp[i] != -1:
		continue
	dp[i] = min(
		dp[i // 3] if i % 3 == 0 else MAX,
		dp[i // 2] if i % 2 == 0 else MAX,
		dp[i - 1]) + 1

print(dp[X])