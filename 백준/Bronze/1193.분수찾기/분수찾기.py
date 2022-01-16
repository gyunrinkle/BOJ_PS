import timeit

def main():
    
    n=int(input())
    start=timeit.default_timer()    
    i=1
    sum=0
    
    while sum<n:
        sum+=i
        i+=1
    
    x=(sum-n)+1
    y=i-x
    
    if i%2==1:
        x,y=y,x
        
    print('{0}/{1}'.format(x,y))
    
    end=timeit.default_timer()
    #print(end-start)
if __name__=='__main__':
    
    main()
    