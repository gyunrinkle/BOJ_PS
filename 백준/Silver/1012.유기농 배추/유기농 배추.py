from collections import deque


def bfs(start_pos):

    cnt = 0
    queue.append(start_pos)

    while queue:

        cur = queue.popleft()
        (cur_i, cur_j) = cur

        # print(cur, matrix[cur_i][cur_j])
        if matrix[cur_i][cur_j] == False:

            matrix[cur_i][cur_j] = True
            cnt += 1

            for k in range(4):

                ni = cur_i + dir_i[k]
                nj = cur_j + dir_j[k]

                if 0 <= ni <= (n - 1) and 0 <= nj <= (m - 1):

                    if matrix[ni][nj] == False:

                        queue.append((ni, nj))

    return cnt


dir_i = [-1, 1, 0, 0]
dir_j = [0, 0, -1, 1]

t = int(input())

배추흰지렁이 = []
for _ in range(t):

    m, n, k = map(int, input().split())

    promising_pos = []

    for i in range(k):
        a, b = map(int, input().split())
        a, b = b, a
        promising_pos.append((a, b))

    matrix = [[False if (i, j) in promising_pos else True for j in range(m)]
              for i in range(n)]

    queue = deque()

    배추흰지렁이.append(0)

    for pos in promising_pos:

        cnt = bfs(pos)

        if cnt != 0:
            배추흰지렁이[_] += 1


for i in range(t):
    print(배추흰지렁이[i])
