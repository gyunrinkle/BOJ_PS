import sys
import re

input = sys.stdin.readline
print = sys.stdout.write

expression = input().strip()
expression = list(filter(lambda x : x != '', re.split(r'\b', expression)))
stack = []
stack_sum = 0

for idx, operator in enumerate(expression):
    if idx == 0:
        stack.append(int(expression[idx]))
        continue
    if operator == '-':
        stack.append(int(expression[idx + 1]))
        continue
    if operator == '+':
        stack[-1] += int(expression[idx + 1])
 
for idx, num in enumerate(stack):
    if idx == 0:
        stack_sum += num
        continue
    
    stack_sum -= num

print(f'{stack_sum}\n')
    


        

