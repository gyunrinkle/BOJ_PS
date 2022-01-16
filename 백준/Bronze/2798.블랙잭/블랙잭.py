
n,m=map(int,input().split())
lst=list(map(int,input().split()))

min_=-1
min_sum=0
for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            sum_=lst[i]+lst[j]+lst[k]
            if sum_> m:
                continue
            d=abs(m-sum_)
            if min_==-1:
                min_=d
            else:
                if min_ > d:
                    min_=d
                    min_sum=sum_

print(min_sum)
                
