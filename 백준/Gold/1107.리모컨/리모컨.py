N = int(input()) #target channel
M = int(input())
broken_btn = []
btn = []
if M != 0:
    broken_btn = list(map(int, input().split()))
btn = [i for i in range(10) if i not in broken_btn]

cur_chn = 100
pressed_cnt = abs(N - cur_chn)

for i in range(1000000):
    continue_trigger = False
    for j in map(int, list(str(i))):
        if j not in btn:
            continue_trigger = True
            break

    if continue_trigger:
        continue
    else:
        pressed_cnt = min(pressed_cnt, len(str(i)) + abs(N - i))

print(pressed_cnt)