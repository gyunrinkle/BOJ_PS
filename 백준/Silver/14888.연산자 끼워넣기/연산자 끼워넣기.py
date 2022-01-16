def plus(a, b):
    return a + b

def minus(a, b):
    return a - b

def times(a, b):
    return a * b

def divide(a, b):
    return a // b if a * b > 0 else -1 * ((-1 * a) // b) 

def dfs(level, res):
    if level == n - 1:

        global maximum, minimum

        if res > maximum:
            maximum = res
        
        if res < minimum:
            minimum = res

        return
    
    for operator in operators_count:
        if operators_count[operator] == 0:
            continue

        prev_res = res
        cal_res = operators_func[operator](res, operands[level + 1])
        res = cal_res
        operators_count[operator] -= 1

        dfs(level + 1, res)

        res = prev_res
        operators_count[operator] += 1
    
    return


n = int(input())
operands = list(map(int, input().split()))
operators_count ={['add','sub','mul','div'][i]: count for i, count in enumerate(list(map(int, input().split())))}
operators_func = {'add': plus, 'sub': minus, 'mul': times, 'div': divide}
maximum = -1000000001
minimum = 1000000001
dfs(0, operands[0])
print(maximum)
print(minimum)


        
        
        


    
