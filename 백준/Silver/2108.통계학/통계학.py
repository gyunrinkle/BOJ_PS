import sys

n = int(sys.stdin.readline())
arr = [0 for _ in range(8000 + 1)]
arr_cpy = [0 for _ in range(8000 + 1)]
sum = 0
min = 4001
max = -4001
max_cnt = 0


for _ in range(n):
    input = int(sys.stdin.readline())
    sum += input
    arr[input + 4000] += 1

prev_i_value = 0

for i in range(8000 + 1):
    if arr[i] == 0:
        continue

    i_R = i - 4000
    if i_R < min:
        min = i_R
    if i_R > max:
        max = i_R
    if arr[i] > max_cnt:
        max_cnt = arr[i]

    arr_cpy[i] = arr[i]

    arr[i] = arr[i] + prev_i_value
    prev_i_value = arr[i]

avg = round(sum / n)
sys.stdout.write(f'{avg}\n')

key = (arr[max + 4000] + 1) // 2
for i in range(max + 4000, min + 4000 - 1, -1):

    if arr[i] == 0:
        continue
    
    if arr[i] == key:
        sys.stdout.write(f'{i - 4000}\n')
        break
    
    if key >= (arr[i] - arr_cpy[i] + 1):
        sys.stdout.write(f'{i - 4000}\n')
        break


mode = arr_cpy.index(max_cnt)

if arr_cpy.count(max_cnt) == 1:
    sys.stdout.write(f'{mode - 4000}\n')
else:
    sys.stdout.write(f'{arr_cpy.index(max_cnt, mode + 1, 8000)  - 4000}\n')

sys.stdout.write(f'{max - min}\n')







