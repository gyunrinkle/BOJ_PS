import sys

def dfs(begin):
    
    if len(stck) == m:
        sys.stdout.write(' '.join(map(str, stck)) + '\n')
        return

    for i in range(begin, n + 1):
        stck.append(i)
        dfs(i)
        stck.pop()

n, m = map(int, sys.stdin.readline().split())
stck = []

dfs(1)