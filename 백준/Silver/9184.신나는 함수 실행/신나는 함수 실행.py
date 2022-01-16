import sys


def w(a, b, c):

    if a <= 0 or b <= 0 or c <= 0:
        return 1

    if a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)

    if dp[a][b][c]:
        return dp[a][b][c]

    if a < b and b < c:
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return dp[a][b][c]

    dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + \
        w(a-1, b, c-1) - w(a-1, b-1, c-1)

    return dp[a][b][c]


MAX = 21
bIterationTrigger = True
dp = [[[0 for _ in range(MAX)] for __ in range(MAX)] for ___ in range(MAX)]

while bIterationTrigger:

    a, b, c = map(int, sys.stdin.readline().split())

    if a == -1 and b == -1 and c == -1:
        bIterationTrigger = False
    else:
        print(f'w({a}, {b}, {c}) = {w(a, b, c)}')
