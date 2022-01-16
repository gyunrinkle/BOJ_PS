def main():
    
    StaticCost,DynamicPrice,Price=map(int,input().split())
    
    if DynamicPrice>=Price:
        print(-1)
    else:
        print(StaticCost//(Price-DynamicPrice)+1)

if __name__=="__main__":
    
    main()