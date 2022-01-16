from collections import deque

n = int(input()) # node 개수
m = int(input()) # edge 개수
adjacent_lists = [list() for _ in range(n + 1)] # 인접 리스트
queue = deque() # queue for bfs
is_visited = [False for _ in range(n + 1)] #is_visited list
cnt = 0 #count
for i in range(m):
    a, b = map(int, input().split())
    adjacent_lists[a].append(b)
    adjacent_lists[b].append(a)

def bfs():

    global cnt

    queue.append(1)
    
    while queue:
        

        cur = queue.popleft()

        if is_visited[cur] == True:
            continue

        is_visited[cur] = True
        cnt += 1

        cur_linked_list = adjacent_lists[cur]

        for i in cur_linked_list:

            if is_visited[i] == True:
                continue

            queue.append(i)
        
bfs()
print(cnt - 1)
