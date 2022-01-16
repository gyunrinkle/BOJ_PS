def dfs(start_v):

    stack = []
    stack.append((1, start_v))

    while stack:

        color, cur = stack.pop()

        if is_visited[cur] == 0:
            is_visited[cur] = color

            for n_v in adjacent_lists[cur]:

                if is_visited[n_v] == color:
                    return False
                
                if is_visited[n_v] == 0:
                    stack.append((3 - color, n_v))
    
    return True

k = int(input())

for _ in range(k):

    v, e = map(int, input().split())
    adjacent_lists = [[] for __ in range(v + 1)]
    is_visited = [0] * (v + 1)

    for __ in range(e):
        v1, v2 = map(int, input().split())
        adjacent_lists[v1].append(v2)
        adjacent_lists[v2].append(v1)
    
    for i in range(1, v + 1):
        adjacent_lists[i].sort()
        adjacent_lists[i].reverse()

    #dfs
    is_bipartite = bool()
    for i in range(1, v + 1):
        
        is_bipartite = dfs(i)

        if is_bipartite == False:
            break
    
    print('YES' if is_bipartite else 'NO')