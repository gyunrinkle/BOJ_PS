import sys

def dfs():
    
    if len(stck) == m:
        sys.stdout.write(' '.join(map(str, stck))+'\n')
        return

    for i in range(1,n+1):

        if i in stck:
            continue

        stck.append(i)
        dfs()
        stck.pop()    

n, m = map(int, sys.stdin.readline().split())

stck = []

dfs()


