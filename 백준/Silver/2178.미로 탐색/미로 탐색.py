from collections import deque

n, m = map(int, input().split())
maze = [list(map(int, list(input()))) for i in range(n)]
dir_i = [-1, 1, 0, 0]
dir_j = [0, 0, -1, 1]
queue = deque()


def bfs():

    queue.append((0, 0, 0))

    while queue:

        cur = queue.popleft()
        cnt, cur_i, cur_j = cur

        if maze[cur_i][cur_j] == 1:

            cnt += 1
            maze[cur_i][cur_j] = 0

            if cur_i == (n - 1) and cur_j == (m - 1):
                return cnt

            for k in range(4):

                ni = cur_i + dir_i[k]
                nj = cur_j + dir_j[k]

                if 0 <= ni <= (n - 1) and 0 <= nj <= (m - 1):
                    if maze[ni][nj] == 1:
                        queue.append((cnt, ni, nj))


print(bfs())
