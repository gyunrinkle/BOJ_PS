from collections import deque
t = int(input())

directs = [
    (-1, 2),
    (-2, 1),
    (-2, -1),
    (-1, -2),
    (1, -2),
    (2, -1),
    (2, 1),
    (1, 2)]

for _ in range(t):

    l = int(input())
    start_i, start_j = map(int, input().split())
    goal_i, goal_j = map(int, input().split())

    matrix = [[0 for __ in range(l)] for _ in range(l)]
    
    #bfs
    queue = deque()
    queue.append((0, start_i, start_j))

    while queue:
        cnt, cur_i, cur_j = queue.popleft()

        if matrix[cur_i][cur_j] == 0:
            matrix[cur_i][cur_j] = 1
            cnt += 1
            
            if cur_i == goal_i and cur_j == goal_j:
                print(cnt - 1)
                break

            for direct in directs:
                ni = cur_i + direct[0]
                nj = cur_j + direct[1]

                if 0 <= ni <= (l -1) and 0 <= nj <= (l -1):
                    if matrix[ni][nj] == 0:
                        queue.append((cnt, ni, nj))
                        