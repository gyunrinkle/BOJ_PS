import sys
import collections

def bfs():

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    queue.append((0, 0, 0))
    is_visited[0][0][0] = 1
    
    while len(queue) != 0:

        cur = queue.popleft()
        (is_broken, i, j) = cur

        if (i, j) == (n - 1, m - 1):
            return is_visited[is_broken][i][j]
        
        for (next_i, next_j) in [(i + _dir[0], j + _dir[1]) for _dir in directions]:

            if next_i < 0 or next_i > (n - 1) or next_j < 0 or next_j > (m - 1) :
                
                continue
            
            if is_visited[is_broken][next_i][next_j] != 0:
               
                continue
            
            if maze[next_i][next_j] == 0 and is_visited[is_broken][next_i][next_j] == 0:
                
                is_visited[is_broken][next_i][next_j] = is_visited[is_broken][i][j] + 1
                queue.append((is_broken, next_i, next_j))
                continue
            
            if maze[next_i][next_j] == 1 and  is_broken == 0:
                
                is_visited[1][next_i][next_j] = is_visited[is_broken][i][j] + 1
                queue.append((1, next_i, next_j))
                continue
        
    return -1
            

n, m = map(int, input().split())
maze = [(list(map(int, list(input())))) for _ in range(n)]
is_visited = [[[0] * m for __ in range(n)] for _ in range(2)]
queue = collections.deque()
print(bfs())











