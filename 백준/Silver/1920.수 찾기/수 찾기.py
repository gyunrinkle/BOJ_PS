n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

def binary_search(a, target, low, high):
    if high < low:
        return False
    
    mid = (low + high) // 2

    if target < a[mid]:
        return binary_search(a, target, low, mid - 1)
    
    if target > a[mid]:
        return binary_search(a, target, mid + 1, high)
    
    return True #found

a.sort()

for i in range(m):

    if binary_search(a, b[i], 0, n - 1) == True:
        print(1)
        continue

    print(0)

    
