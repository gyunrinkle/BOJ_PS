
def OnetoZero(i_,j_,n,arr):

    if n==0:
        return

    for i in range(n,2*n):
        for j in range(n,2*n):
            arr[i_+i][j_+j]=0
    
    #8개의 분기로 구분
    OnetoZero(i_,j_,n//3,arr)
    OnetoZero(i_,j_+n,n//3,arr)
    OnetoZero(i_,j_+2*n,n//3,arr)

    OnetoZero(i_+n,j_,n//3,arr)
    OnetoZero(i_+n,j_+2*n,n//3,arr)

    OnetoZero(i_+2*n,j_,n//3,arr)
    OnetoZero(i_+2*n,j_+n,n//3,arr)
    OnetoZero(i_+2*n,j_+2*n,n//3,arr)



def main():

    n=int(input())

    arr=[[1 for j in range(n)] for i in range(n)]

    OnetoZero(0,0,n//3,arr)
    
  

    for i in range(n):

        for j in range(n):
            if arr[i][j]==1:
                print('*',end='')
            else:
                print(' ',end='')
        
        print()


if __name__=='__main__':

    main()