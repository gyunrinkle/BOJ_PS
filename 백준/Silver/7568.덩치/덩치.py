n = int(input())
people = [tuple(map(int, input().split())) for _ in range(n)]
for i in range(n):
    cnt = 0
    for j in range(n):
        if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
            cnt += 1
    print(cnt + 1, end=' ')
print()
