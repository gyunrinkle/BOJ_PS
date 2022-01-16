import collections

n = int(input())
cnt = 0
queue = collections.deque()

def recursive(n, a, b):
    if n == 1:
        global cnt
        queue.append((a, b))
        cnt = cnt + 1
        return
    
    recursive(n - 1, a, 6 - a - b)
    recursive(1, a, b)
    recursive(n - 1, 6 - a - b, b)


recursive(n, 1, 3)
print(cnt)
while(len(queue) > 0):
    tmp = queue.popleft()
    print(tmp[0], tmp[1])


