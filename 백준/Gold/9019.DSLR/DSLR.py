from collections import deque
import sys
input = sys.stdin.readline
def bfs(src, target):
    is_visited = [False for _ in range(10000)]
    dslr_dict = {'D': D, 'S': S, 'L': L, 'R': R}
    q = deque()
    for key in dslr_dict:
        q.append([dslr_dict[key](src), key])
    while q:
        cur = q.popleft()
        if is_visited[cur[0]] == False:
            is_visited[cur[0]] = True

            if cur[0] == target:
                return cur[1]

            for key in dslr_dict:
                if is_visited[dslr_dict[key](cur[0])]:
                    continue

                q.append([dslr_dict[key](cur[0]), cur[1] + key])
                
def D(digit):
    return (2 * digit) % 10000

def S(digit):
    return 9999 if digit == 0 else digit - 1

def L(digit):
    return (digit // 1000) + (digit % 1000) * 10

def R(digit):
    return (digit % 10) * 1000 + (digit // 10)

def main():
    T = int(input())
    for _ in range(T):
        A, B = map(int, input().split())
        print(bfs(A, B))

if __name__ == '__main__':
    main()
