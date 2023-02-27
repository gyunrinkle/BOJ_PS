import sys

# sys.stdin = open("input.txt", "r")
input = sys.stdin.readline


def read_input():
    global N, M
    N, M = map(int, input().rstrip().split())


def DFS_preorder(root, level, visited_num_list):
    if level >= M:
        print(" ".join(map(str, visited_num_list)))
        return
    for i in range(1, N + 1):
        if i == root:
            continue
        if i in visited_num_list:
            continue
        DFS_preorder(i, level + 1, [*visited_num_list, i])


def solve():
    for i in range(1, N + 1):
        DFS_preorder(i, 1, [i])


if __name__ == "__main__":
    read_input()
    solve()
