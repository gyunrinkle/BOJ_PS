import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input().rstrip())
arr = [int(input().rstrip()) for _ in range(N)]
arr.sort()
for n in arr:
    print(f'{n}\n')
