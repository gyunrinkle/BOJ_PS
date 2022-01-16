def main():
    k=int(input())
    stck=[]
    for i in range(k):
        n=int(input())
        if n==0:
            stck.pop()
        else:
            stck.append(n)

    if len(stck)==0:
        print(0)
    else:
        sum=0
        for i in range(len(stck)):
            sum+=stck[i]

        print(sum)    
        

if __name__=='__main__':
    main()