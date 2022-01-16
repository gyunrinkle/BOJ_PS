from collections import deque
import sys
m, n = map(int, input().split())
warehouse = [list(map(int, input().split())) for _ in range(n)]
ripe_tomato_pos = [(i, j) for j in range(m) for i in range(n) if warehouse[i][j] == 1]
unripe_tomato_cnt = 0
cnt = 0
queue = deque()
day_max = 0
dir_i = [-1, 1, 0, 0]
dir_j = [0, 0, -1, 1]

for i in range(n):
    unripe_tomato_cnt += warehouse[i].count(0)

if unripe_tomato_cnt == 0:
    print(0)
    sys.exit(0)

for pos in ripe_tomato_pos:
    pos_i, pos_j = pos
    for k in range(4):
        npos_i = pos_i + dir_i[k]
        npos_j = pos_j + dir_j[k]

        if 0 <= npos_i <= (n - 1) and 0 <= npos_j <= (m - 1):
            if warehouse[npos_i][npos_j] == 0:
                queue.append((1, npos_i, npos_j))

def bfs():
    global cnt, day_max
    while queue:
        cur = queue.popleft()
        days, cur_i, cur_j = cur

        if warehouse[cur_i][cur_j] == 0:
            
            warehouse[cur_i][cur_j] = 1
            cnt += 1

            if days > day_max:
                day_max = days

            for k in range(4):
                ni = cur_i + dir_i[k]
                nj = cur_j + dir_j[k]

                if 0 <= ni <= (n - 1) and 0 <= nj <= (m - 1):
                    if warehouse[ni][nj] == 0:
                        queue.append((days + 1, ni, nj))

bfs()
if cnt != unripe_tomato_cnt:
    print(-1)
    sys.exit(0)

print(day_max)