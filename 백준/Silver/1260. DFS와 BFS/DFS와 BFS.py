import sys
from collections import deque

# sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

adjacent_list = [[] for _ in range(1000 + 1)]
is_visited = [False for _ in range(1000 + 1)]


def read_input():
    global N, M, src
    N, M, src = map(int, input().rstrip().split())
    for _ in range(M):
        u, v = map(int, input().rstrip().split())
        adjacent_list[u].append(v)
        adjacent_list[v].append(u)


def init_is_visisted():
    for i in range(1000 + 1):
        is_visited[i] = False


def DFS():
    adjacent_list_for_DFS = [sorted(l, reverse=True) for l in adjacent_list]
    stack = []
    stack.append(src)

    while stack:
        cur = stack.pop()
        if is_visited[cur]:
            continue

        for nv in adjacent_list_for_DFS[cur]:
            stack.append(nv)
        is_visited[cur] = True
        print(cur, end=" ")


def BFS():
    adjacent_list_for_BFS = [sorted(l) for l in adjacent_list]
    queue = deque()
    queue.append(src)

    while queue:
        cur = queue.popleft()
        if is_visited[cur]:
            continue

        for nv in adjacent_list_for_BFS[cur]:
            queue.append(nv)

        is_visited[cur] = True
        print(cur, end=" ")


def solve():
    DFS()
    print()
    init_is_visisted()
    BFS()


if __name__ == "__main__":
    read_input()
    solve()
