import sys
sys.setrecursionlimit(1500)
MAX = 1000
X = input()
Y = input()
dp = [[-1] * MAX for _ in range(MAX)]
if X[0] == Y[0]:
    dp[0][0] = 1
else:
    dp[0][0] = 0

def LCS(X_i, Y_j):

    if X_i < 0 or Y_j < 0:
        return 0

    if dp[X_i][Y_j] != -1:
        return dp[X_i][Y_j] 
    
    if X[X_i] == Y[Y_j]:
        dp[X_i][Y_j] = LCS(X_i - 1, Y_j - 1) + 1
    else:
        dp[X_i][Y_j] = max(LCS(X_i - 1, Y_j), LCS(X_i, Y_j - 1))
    
    return dp[X_i][Y_j]

print(LCS(len(X) - 1, len(Y) - 1))
    