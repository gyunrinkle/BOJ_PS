n = int(input())
skew_matrix = [list(map(int, input().split())) for _ in range(n)]
member_list = [i for i in range(n)]
minimum = 10000000
start = []

def dfs(level, cur):
    if level == n // 2 - 1:
        link = list(filter(lambda x : x not in start, member_list))
        # print(start)
        # print(link)
        # print('----------------')
        length = n // 2
        start_sum = 0
        link_sum = 0
        for i in range(length):
            for j in range(i + 1, length):
                start_sum += skew_matrix[start[i]][start[j]] + skew_matrix[start[j]][start[i]]
                link_sum += skew_matrix[link[i]][link[j]] + skew_matrix[link[j]][link[i]]

        global minimum

        if abs(start_sum - link_sum) < minimum:
            
            minimum = abs(start_sum - link_sum)
    
        return
    
    for i in range(cur + 1, n):
        start.append(i)
        dfs(level + 1, i)
        start.pop()
    
    return

start.append(0)
dfs(0, 0)
start.pop()
print(minimum)


