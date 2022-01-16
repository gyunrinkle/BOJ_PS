n = int(input())
sequence = list(map(int, input().split()))
sequence_reverse = sequence[::-1]
dp = [0] * n
dp_reverse = [0] * n

for i in range(n):

    if i == 0:
        dp[i] = 1
        dp_reverse[i] = 1
        continue
    
    maximum = -9999
    maximum_reverse = -9999

    for j in range(i):

        if sequence[j] < sequence[i]:
            if dp[j] > maximum:
                maximum = dp[j]
        
        if sequence_reverse[j] < sequence_reverse[i]:
            if dp_reverse[j] > maximum_reverse:
                maximum_reverse = dp_reverse[j]
    
    if maximum < 0:
        dp[i] = 1
    else:
        dp[i] = maximum + 1

    if maximum_reverse < 0:
        dp_reverse[i] = 1
    else:
        dp_reverse[i] = maximum_reverse + 1

dp_reverse.reverse()

dp_sum = [a + b for a, b in zip(dp, dp_reverse)]

print(max(dp_sum) - 1)