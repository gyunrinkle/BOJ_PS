from collections import deque
import sys

m, n, h = map(int, input().split())

warehouse = [[list(map(int, input().split())) for __ in range(n)] for _ in range(h)] #토마토 위치 정보 3차원 배열로 실체화


ripe_tomato_pos = [(i, j, k) for k in range(m) for j in range(n) for i in range(h) if warehouse[i][j][k] == 1] #초기 설정에서 익은 토마토의 위치


unripe_tomato_cnt = 0
cnt = 0
day_max = 0


#위, 아래, 왼쪽, 오른쪽, 앞, 뒤
dir_i = [1, -1, 0, 0, 0, 0]
dir_j = [0, 0, 0, 0, 1, -1]
dir_k = [0, 0, -1, 1, 0, 0]

queue = deque()


#안 익은 토마토 개수 세기
for i in range(h):
    for j in range(n):
        unripe_tomato_cnt += warehouse[i][j].count(0)



#안 익은 토마토가 없다면 프로그램 종료
if unripe_tomato_cnt == 0:
    print(0)
    sys.exit(0)

#만약 1개라도 있다면
for pos in ripe_tomato_pos:

    pos_i, pos_j, pos_k = pos

    for l in range(6):
        npos_i = pos_i + dir_i[l]
        npos_j = pos_j + dir_j[l]
        npos_k = pos_k + dir_k[l]

        if 0 <= npos_i <= (h - 1) and 0 <= npos_j <= (n - 1) and 0 <= npos_k <= (m - 1):
            if warehouse[npos_i][npos_j][npos_k] == 0:
                queue.append((1, npos_i, npos_j, npos_k))

#bfs
def bfs():

    global cnt, day_max

    while queue:
        cur = queue.popleft()
        days, cur_i, cur_j, cur_k = cur

        if warehouse[cur_i][cur_j][cur_k] == 0:
            
            warehouse[cur_i][cur_j][cur_k] = 1
            cnt += 1

            if days > day_max:
                day_max = days

            for l in range(6):
                ni = cur_i + dir_i[l]
                nj = cur_j + dir_j[l]
                nk = cur_k + dir_k[l]

                if 0 <= ni <= (h - 1) and 0 <= nj <= (n - 1) and 0 <= nk <= (m - 1):
                    if warehouse[ni][nj][nk] == 0:
                        queue.append((days + 1, ni, nj, nk))

bfs()
if cnt != unripe_tomato_cnt:
    print(-1)
    sys.exit(0)

print(day_max)