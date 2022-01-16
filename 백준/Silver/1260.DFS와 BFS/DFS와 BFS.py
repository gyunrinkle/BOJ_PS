from collections import deque

n, m, v = map(int, input().split())
adjacent_lists = [list() for _ in range(n + 1)]
is_visited = [False for _ in range(n + 1)]
stack = []
queue = deque()

for i in range(m):
    a, b = map(int, input().split())
    adjacent_lists[a].append(b)
    adjacent_lists[b].append(a)

for i in range(1, n + 1):
    adjacent_lists[i].sort()
    adjacent_lists[i].reverse()

def dfs():

    stack.append(v)
   

    while stack:
        cur = stack.pop()

        if is_visited[cur] == False:

            is_visited[cur] = True
            print(cur, end = ' ')

            cur_list = adjacent_lists[cur]

            for i in range(len(cur_list)):
                if is_visited[cur_list[i]] == True:
                    continue

                stack.append(cur_list[i])
        
dfs()
print()
is_visited = [False for _ in range(n + 1)]

for i in range(1, n + 1):
    adjacent_lists[i].sort()
    

def bfs():

    queue.append(v)

    while queue:

        cur = queue.popleft()

        if is_visited[cur] == False:

            is_visited[cur] = True
            print(cur, end = ' ')

            cur_list = adjacent_lists[cur]

            for i in range(len(cur_list)):
                if is_visited[cur_list[i]] == True:
                    continue
                    
                queue.append(cur_list[i])


bfs()
print()
    
    




