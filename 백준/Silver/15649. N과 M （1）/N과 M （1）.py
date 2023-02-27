import sys
from itertools import permutations

# sys.stdin = open("input.txt", "r")
input = sys.stdin.readline


def read_input():
    global N, M
    N, M = map(int, input().rstrip().split())


def solve():
    for ans_tuple in permutations(range(1, N + 1), M):
        print(" ".join(map(str, ans_tuple)))


if __name__ == "__main__":
    read_input()
    solve()
