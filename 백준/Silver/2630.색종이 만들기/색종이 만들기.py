n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
blue_cnt = 0
white_cnt = 0

def is_same_color(start_i, start_j, n):

    #sub_matrix 생성
    sub_matrix = []
    for i in range(start_i, start_i + n):
        sub_matrix.append(matrix[i][start_j:start_j + n])

    #검사    
    if any(1 in row for row in sub_matrix) and any(0 in row for row in sub_matrix):      
        return False
    
    return True

def divide_and_conquer(start_i, start_j, n):
    
    if is_same_color(start_i, start_j, n):
        global blue_cnt, white_cnt
        if matrix[start_i][start_j] == 1:
            blue_cnt += 1
        else:
            white_cnt += 1

        return
    
    #n을 반으로 쪼갬
    n = n // 2
    divide_and_conquer(start_i, start_j, n)
    divide_and_conquer(start_i, start_j + n, n)
    divide_and_conquer(start_i + n, start_j, n)
    divide_and_conquer(start_i + n, start_j + n, n)

    
divide_and_conquer(0, 0, n)
print(white_cnt)
print(blue_cnt)


