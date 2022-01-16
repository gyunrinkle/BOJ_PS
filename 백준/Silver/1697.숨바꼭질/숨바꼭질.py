from collections import deque
import sys

n, k = map(int, input().split())
is_visit = [0 for _ in range(100000 + 1)]
queue = deque()


def bfs():
    queue.append((0, n))

    while queue:

        cnt, cur = queue.popleft()
        
        if is_visit[cur] == 0:

            is_visit[cur] = 1
            cnt += 1

            if cur == k:
                print(cnt - 1)
                sys.exit(0)
            
            n_cur = cur - 1
            if 0 <= n_cur <= 100000 and is_visit[n_cur] == 0:
                queue.append((cnt, n_cur))

            n_cur = cur + 1
            if 0 <= n_cur <= 100000 and is_visit[n_cur] == 0:
                queue.append((cnt, n_cur))
            
            n_cur = cur * 2
            if 0 <= n_cur <= 100000 and is_visit[n_cur] == 0:
                queue.append((cnt, n_cur))
                

bfs()