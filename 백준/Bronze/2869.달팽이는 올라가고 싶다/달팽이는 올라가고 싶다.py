import math

def main():
    a,b,v=map(int,input().split())
    

    print(math.ceil((v-a)/(a-b))+1)




if __name__=='__main__':

    main()