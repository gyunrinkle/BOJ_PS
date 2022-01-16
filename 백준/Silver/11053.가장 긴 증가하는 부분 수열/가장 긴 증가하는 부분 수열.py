n = int(input())
sequence = list(map(int, input().split()))
dp = [0 for _ in range(n)]

for i in range(n):

    if i == 0:
        dp[i] = 1
        continue
    
    maximum = -99999


    for j in range(i):
        
        if sequence[j] < sequence[i]:
            if dp[j] > maximum:
                maximum = dp[j]

   
    if maximum < 0:
        dp[i] = 1
        continue

    dp[i] = maximum + 1


dp.sort()
print(dp[n - 1])