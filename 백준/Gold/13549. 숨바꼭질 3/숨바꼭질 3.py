import sys
from heapq import *

input = sys.stdin.readline

INF = 10**9
N, K = None, None
dist = [INF for _ in range(10**5 + 1)]
dir_list = [(1, -1), (1, 1), (2, 0)]


def read_input():
    global N, K
    N, K = map(int, input().rstrip().split())


def solve():
    min_heap = [(0, N)]
    while min_heap:
        cur_dist, cur_node = heappop(min_heap)
        if cur_dist >= dist[cur_node]:
            continue
        dist[cur_node] = cur_dist

        for dir_tuple in dir_list:
            a, b = dir_tuple
            next_dist, next_node = (1 if b != 0 else 0) + cur_dist, (a * cur_node + b)
            if next_node < 0 or next_node > 10**5:
                continue
            heappush(min_heap, (next_dist, next_node))

    return dist[K]


if __name__ == "__main__":
    read_input()
    ans = solve()
    print(ans)
