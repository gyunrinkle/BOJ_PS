n, m = map(int, input().split())

board = [ list(input()) for _ in range(n)]

w_board = [
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
    ]

b_board = [
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
    ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
    ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
    ]

minimum = 1000000

for i in range(n):

    for j in range(m):

        if i + 8 > n or j + 8 > m:
            continue
        
        w_cnt = 0
        b_cnt = 0

        for idx_i in range(8):

            for idx_j in range(8):

                if board[i + idx_i][j + idx_j] != w_board[idx_i][idx_j]:
                    w_cnt += 1

                if board[i + idx_i][j + idx_j] != b_board[idx_i][idx_j]:
                    b_cnt += 1

        cnt = w_cnt if w_cnt < b_cnt else b_cnt

        if cnt < minimum:
            minimum = cnt

print(minimum)

