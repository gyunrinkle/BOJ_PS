import sys
import math

input = sys.stdin.readline
print = sys.stdout.write

T = int(input().strip())

for _ in range(T):
    N = int(input().strip())
    if N % 9 == 0 or N % 3 == 2:
        print(f'TAK\n')
    else:
        print(f'NIE\n')