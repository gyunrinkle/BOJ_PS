import sys

input = sys.stdin.readline
print = sys.stdout.write

MAX = 26
N = int(input().rstrip())
tree = {} # dictionary
is_visited = [False] * MAX

def dfs(root): # dfs랑 동일
    if is_visited[ord(root) - ord('A')] == True:
        return
    
    is_visited[ord(root) - ord('A')] = True
    print(f'{root}')
    
    for child in tree[root]:
        if child == '.':
            continue
        if is_visited[ord(child) - ord('A')] == True:
            continue
        pre_order(child)

def pre_order(root):

    if root == '.':
        return

    print(f'{root}')
    pre_order(tree[root][0])
    pre_order(tree[root][1])

def in_order(root):
    if root == '.':
        return
    
    in_order(tree[root][0])
    print(f'{root}')
    in_order(tree[root][1])

def post_order(root):
    if root == '.':
        return
    
    post_order(tree[root][0])
    post_order(tree[root][1])
    print(f'{root}')

for i in range(N): #tree 입력 받기
    root, left, right = map(str, input().rstrip().split())
    tree[root] = [left, right]


# dfs('A')
# print('\n')

pre_order('A')
print('\n')

in_order('A')
print('\n')

post_order('A')
print('\n')





