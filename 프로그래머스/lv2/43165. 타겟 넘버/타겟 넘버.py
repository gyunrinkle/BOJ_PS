def solution(numbers, target):
    answer = 0
    
    len_numbers = len(numbers)
    def dfs(depth, cur_sum):
        nonlocal answer
        if depth >= len_numbers:
            if cur_sum == target:
                answer += 1
            
            return
        
        dfs(depth+1, cur_sum + numbers[depth])
        dfs(depth+1, cur_sum + (-numbers[depth]))
    
    dfs(1, numbers[0])
    dfs(1, -numbers[0])
    return answer

print(solution([1,1,1,1,1],3))
