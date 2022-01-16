import re

iteration_trigger = True

while iteration_trigger:
    string = input()

    if string == '.':
        iteration_trigger = False
        continue
    
    p = re.compile('[\[\]\(\)]')
    m = p.findall(string)

    if len(m) == 0:
        print('yes')
        continue

    stack = []

    while m:

        if len(stack) == 0:
            stack.append(m.pop())
            continue
           
        tmp = m.pop()
        tmp_string = tmp + stack[-1] 

        if tmp_string == '()' or tmp_string =='[]':
            stack.pop()
            continue
        
        stack.append(tmp)
    
    if stack:
        print('no')
        continue

    print('yes')
    
