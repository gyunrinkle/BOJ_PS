import sys
# sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline
print = sys.stdout.write

S = input().rstrip()
T = input().rstrip()
A = [0] * len(T)

for i in range(len(S)):
    for j in range(len(T)):
        if S[i] == T[j]:
            if j == 0:
                A[j] += 1
                continue
            if A[j] < A[j - 1]:
                A[j] += 1
                continue 

print(f'{A[len(T) - 1]}\n')