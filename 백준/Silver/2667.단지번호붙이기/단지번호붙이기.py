from collections import deque
n = int(input()) #n by n matrix
matrix = [list(map(int, list(input()))) for _ in range(n)] #map
promising_starts = [(i, j) for j in range(n) for i in range(n) if matrix[i][j] == 1]
is_visited = [[False if matrix[i][j] == 1 else True for j in range(n)] for i in range(n)]
dir_i = [-1, 1, 0, 0]
dir_j = [0, 0, -1, 1]
queue = deque()
단지수 = []


def bfs(start):

    cnt = 0
    queue.append(start)

    while queue:
        cur = queue.popleft()
        (cur_i, cur_j) = cur

        if is_visited[cur_i][cur_j] == True:
            continue

        is_visited[cur_i][cur_j] = True
        cnt += 1

        for k in range(4):

            ni = cur_i + dir_i[k]
            nj = cur_j + dir_j[k]

            if ni < 0 or ni > (n - 1) or nj < 0 or nj > (n - 1):
                continue

            if is_visited[ni][nj] == True:
                continue

            queue.append((ni, nj))
    
    return cnt


for start in promising_starts:
    queue.clear()
    cnt = bfs(start)
    if cnt == 0:
        continue
    단지수.append(cnt)

단지수.sort()
길이 = len(단지수)

print(길이)
for i in range(길이):
    print(단지수[i])
