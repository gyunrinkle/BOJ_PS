import sys
from collections import deque
input = sys.stdin.readline


N, M = map(int, input().strip().split())

matrix = [list(map(int, list(input().strip()))) for _ in range(N)]
is_visited = [[False for j in range(M)] for i in range(N)]
dir_i = [-1, 1, 0, 0]
dir_j = [0, 0, -1, 1]
answer = [[0 for j in range(M)] for i in range(N)]
flood_matrix = [[0 for j in range(M)] for i in range(N)] 
floods = {} # 홍수 난 곳을 dictionary로 정리 홍수 난 곳 group idx : 홍수 난 범위
flood_idx = 1
dq = deque()
flood_set = set()

def BFS(cur_i, cur_j):
    dq.append((cur_i, cur_j))
    cnt = 0
    while dq:
        ci, cj = dq.popleft()
        if is_visited[ci][cj] == True:
            continue
        is_visited[ci][cj] = True
        flood_matrix[ci][cj] = flood_idx
        cnt += 1

        for di, dj in zip(dir_i, dir_j):
            ni, nj = ci + di, cj + dj
            if ni < 0 or ni >= N or nj < 0 or nj >= M:
                continue
            if is_visited[ni][nj] == True:
                continue
            if matrix[ni][nj] == 1:
                continue
            dq.append((ni, nj))

    return cnt

for i in range(N):
    for j in range(M):
        if matrix[i][j] == 0 and is_visited[i][j] == False:
            floods[flood_idx] = BFS(i, j)
            flood_idx += 1

for i in range(N):
    for j in range(M):
        if matrix[i][j] == 1:
            for di, dj in zip(dir_i, dir_j):
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= N or nj < 0 or nj >= M:
                    continue
                if matrix[ni][nj] == 1:
                    continue
                flood_set.add(flood_matrix[ni][nj])
            
            for f_i in flood_set:
                answer[i][j] += floods[f_i]
            flood_set.clear()
            answer[i][j] += 1
                
for i in range(N):
    for j in range(M):
        sys.stdout.write(f'{answer[i][j] % 10}')
    sys.stdout.write(f'\n')