import math

def main():

    k=int(input())

    if k==1:
        print(1)
    else:
        k=k-1
        n=int((3+math.sqrt(12*k-3))/6)
        print(n+1)


    
    


if __name__=='__main__':

    main()

    