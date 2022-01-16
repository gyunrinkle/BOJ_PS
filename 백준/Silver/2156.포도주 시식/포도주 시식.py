n = int(input())
dp = [0] * n
glasses = []
for _ in range(n):
    glasses.append(int(input()))

for i in range(n):
    if i == 0:
        dp[i] = glasses[i]
        continue

    if i == 1:
        dp[i] = glasses[i] + glasses[i - 1]
        continue

    if i == 2:
        dp[i] = glasses[i] + max(glasses[i - 1], glasses[i - 2])
        continue

    if i == 3:
        dp[i] = max(glasses[i] + glasses[i - 1] + glasses[i - 3], glasses[i] + dp[i - 2])
        continue
    
    maximum = -9999

    for j in range(i - 2): # 0 ~ (i - 3)

        if dp[j] > maximum:
            maximum = dp[j]

    dp[i] = max(glasses[i] + glasses[i - 1] + maximum, glasses[i] + dp[i - 2] if dp[i -2] > maximum else maximum)


dp.sort()
print(dp[n - 1])
