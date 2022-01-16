def main():
    n=int(input())
    lst=list(map(int,input().split()))
    
    arr=[1 for i in range(1001)]
    arr[1]=0
    for i in range(2,1001):

        bIterationTrigger=True
        j=i
        cnt=2

        while bIterationTrigger:

            j=i*cnt
            cnt+=1

            if j>1000:
                bIterationTrigger=False
                continue

            arr[j]=0
            

    
    cnt=0
    for i in range(n):
        if arr[lst[i]]==1:
            
            cnt+=1
    print(cnt)


if __name__=='__main__':

    main()