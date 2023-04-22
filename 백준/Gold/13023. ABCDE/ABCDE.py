import sys

# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")

input = sys.stdin.readline
print = sys.stdout.write
MAX = 2000

N, M = None, None

# adjacent lists
adjacent_lists = [[] for _ in range(MAX)]
is_visited = [False for _ in range(MAX)]
answer = False

def read_input():
    global N, M
    N, M = map(int, input().rstrip().split())

    
    for _ in range(M):
        a, b = map(int, input().rstrip().split())
        adjacent_lists[a].append(b)
        adjacent_lists[b].append(a)

# 다섯 개의 노드가 한 붓 그리기로 이어지나?
def solve():

    ret = False

    def dfs(start, depth):
        nonlocal ret

        if is_visited[start]:
            return

        is_visited[start] = True

        if depth == 5:
            ret = True
            return
            
        for next_node in adjacent_lists[start]:
            dfs(next_node, depth + 1)
        
        is_visited[start] = False

    for i in range(N):
        dfs(i, 1)
        if ret == True:
            break

    return ret

def write_output():
    print(f"{1 if answer else 0}\n")

read_input()
answer = solve()
write_output()



