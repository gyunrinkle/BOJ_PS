import sys


def mergeSort(begin, end):

    if end - begin < 2:
        return

    middle = (begin + end) // 2
    
    mergeSort(begin, middle)
    mergeSort(middle, end)

    left, right = begin, middle

    for i in range(begin,end):

        if left == middle:
            tmp_lst[i] = src_lst[right]
            right += 1 

        elif right == end:
            tmp_lst[i] = src_lst[left]
            left += 1

        elif src_lst[left] <= src_lst[right]:
            tmp_lst[i] = src_lst[left]
            left += 1
        
        else:
            tmp_lst[i] = src_lst[right]
            right += 1

    for i in range(begin,end):

        src_lst[i] = tmp_lst[i]





src_lst = []

n = int(sys.stdin.readline())

for i in range(n):
    src_lst.append(int(sys.stdin.readline()))

tmp_lst = [0 for _ in range(n)]

mergeSort(0,n)

for i in range(n):
    print(src_lst[i])
    