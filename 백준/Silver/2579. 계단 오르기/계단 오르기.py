import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

n = int(input().rstrip())
points = [int(input().rstrip()) for _ in range(n)]
dp = [0] * n

if n == 1:
    print(points[0])

elif n == 2:
    print(points[0] + points[1])

else:
    dp[0] = points[0]
    dp[1] = points[0] + points[1]
    dp[2] = max(points[2] + points[0], points[2] + points[1])

    for i in range(3, n):
        dp[i] = max(points[i] + points[i - 1] + dp[i - 3], points[i] + dp[i - 2])

    print(dp[n - 1])