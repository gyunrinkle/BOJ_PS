from collections import deque

T = int(input())

for _ in range(T):

    p = list(input()) # 명령어를 한글자씩 분리하기
    n = int(input())
    txt = input()[1:-1].split(',')  
    r_flag = False
    error_flag = False
    if txt == ['']:
        dq = deque()
    else:
        dq = deque(list(map(int, txt)))

    for i in p:
        if i == 'R':
            r_flag = not r_flag
            #dq.reverse()
        elif i == 'D':
            if dq:
                if r_flag:
                    dq.pop()
                else:
                    dq.popleft()
            else:
                print('error')
                error_flag = True
                break
        
    if not error_flag:
        if r_flag:
            dq.reverse()
            print(str(list(dq)).replace(' ', ''))
        else:
            print(str(list(dq)).replace(' ', ''))