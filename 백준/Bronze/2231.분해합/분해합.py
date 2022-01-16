import sys
n = int(input())
iteration_trigger = True
i = 1
while iteration_trigger:
    if i == n:
        print(0)
        sys.exit(0)
        
    sum = 0
    j = i
    while j > 0:
        sum += j % 10
        j //= 10
    sum += i

    if sum == n:
        iteration_trigger = False
        continue
    
    i += 1

print(i)



    
