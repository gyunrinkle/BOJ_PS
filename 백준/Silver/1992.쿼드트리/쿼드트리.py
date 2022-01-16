n = int(input())
matrix = [list(map(int, list(input()))) for _ in range(n)]

def quad_tree(start_i, start_j, n):

    sub_matrix = [matrix[start_i + row_idx][start_j: start_j + n] for row_idx in range(n)]

    if any(1 in row for row in sub_matrix) and any(0 in row for row in sub_matrix):
        print('(', end = '')
        n = n // 2
        quad_tree(start_i, start_j, n)
        quad_tree(start_i, start_j + n, n)
        quad_tree(start_i + n, start_j, n)
        quad_tree(start_i + n, start_j + n, n)
        print(')', end = '')
        return
    
    if sub_matrix[0][0] == 1:
        print(1, end = '')
        return
    
    if sub_matrix[0][0] == 0:
        print(0, end = '')
        return

quad_tree(0, 0, n)
print()