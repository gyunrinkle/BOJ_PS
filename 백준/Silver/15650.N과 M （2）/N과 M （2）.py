import sys


def dfs(begin):
    
    if len(stck) == m:
        sys.stdout.write(' '.join(map(str, stck))+'\n')
        return

    for i in range(begin, n+1):

        if i in stck:
            continue

        stck.append(i)
        dfs(i + 1)
        stck.pop()    


n, m = map(int, sys.stdin.readline().split())

stck = []

dfs(1)


