n = int(input())

i = 1
cnt = 0
iteration_trigger = True
while iteration_trigger:

    if '666' in str(i):
        cnt += 1
    
    if cnt == n:
        iteration_trigger = False
        continue

    i += 1

print(i)