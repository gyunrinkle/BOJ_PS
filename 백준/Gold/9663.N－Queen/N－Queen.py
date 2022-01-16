import sys

def dfs():
    global cnt

    if len(stck) == n:
        cnt += 1
        return 
    
    for i in range(1, n + 1):
        
        if i in stck:
            continue

        else:
            
            b = False

            for j in range(len(stck)):
                if stck[j] + abs(len(stck) - j) == i or stck[j] - abs(len(stck) - j) == i:
                    b = True
                    break
            
            if b:
                continue
            else:
                stck.append(i)
                dfs()
                stck.pop()


n = int(sys.stdin.readline())
cnt = 0
stck = []
dfs()

sys.stdout.write(str(cnt))