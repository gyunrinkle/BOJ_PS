import sys 

matrix = [list(map(int, input().split())) for _ in range(9)]

coord = list(filter(lambda x: x != None, 
    [(i, j) if matrix[i][j] == 0 else None for i in range(9) for j in range(9)]
))
            
n = len(coord)

def is_promising(n, level, cur_i, cur_j):

    '''현재 level에서 coord가 가리키는 좌표가 들어가 있는 
    굵은 선으로 구분되어 있는 3x3 정사각형 구역의 
    최좌측 상단 좌표값(i,j)
    '''
    (sect_i, sect_j) = (int(cur_i / 3) * 3, int(cur_j / 3) * 3)

    # 행에 같은 숫자가 있으면 다음 숫자로 넘어가기(초록색 과정)
    if n in matrix[cur_i]: 
        return False

    # 열에 같은 숫자가 있으면 다음 숫자로 넘어가기(주황색 과정)
    if n in [matrix[i][cur_j] for i in range(0, 9)]: 
        return False

    # 굵은 선으로 구분되어 있는 3x3 정사각형 안에 같은 숫자가 있으면 다음 숫자로 넘어가기(노란색 과정)
    if any(n in row for row in [
        matrix[sect_i][sect_j:sect_j + 3], 
        matrix[sect_i + 1][sect_j:sect_j + 3], 
        matrix[sect_i + 2][sect_j:sect_j + 3]
    ]):
        return False
    
    #위의 세가지 조건에 모두 해당이 안되면 n을 스도쿠의 빈칸에 넣어도 됨
    return True

def dfs(level):

    if level == n:

        for i in range(9):
            for j in range(9):
                if j == 9:
                    print(matrix[i][j], end = '')
                    continue
                print(matrix[i][j], end = ' ')
            print()

        sys.exit(0) # 스도쿠 출력하고 프로그램 바로 종료
    

    # 현재 level에서 coord가 가리키는 좌표값(i, j)
    (cur_i, cur_j) = coord[level]

    for i in range(1, 10): #1부터 10까지 다 집어 넣기
        
        if is_promising(i, level, cur_i, cur_j) == False:
            continue

        

        matrix[cur_i][cur_j] = i
        dfs(level + 1)
        matrix[cur_i][cur_j] = 0
         
    return
    
dfs(0)