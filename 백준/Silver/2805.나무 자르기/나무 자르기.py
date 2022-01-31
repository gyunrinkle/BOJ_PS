import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline
print = sys.stdout.write

N, M = map(int, input().rstrip().split())
heights = list(map(int, input().rstrip().split()))
heights.sort()
s = 0
e = heights[N - 1]
ans = -1

def is_valid(mid):
    summation = 0

    for height in heights:
        if mid > height:
            continue

        summation += height - mid
    
    if summation >= M:
        global ans
        if mid > ans:
            ans = mid

        return True
    
    return False

while s <= e:
    m = (s + e) // 2

    if is_valid(m):
        s = m + 1
        continue

    e = m - 1

print(f'{ans}\n')