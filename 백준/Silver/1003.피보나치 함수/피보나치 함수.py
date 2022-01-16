import sys
    
t=int(sys.stdin.readline())
input_arr=[]


for i in range(t):
    input_arr.append(int(sys.stdin.readline()))

zero_arr=[]
one_arr=[]

zero_arr.append(1)
zero_arr.append(0)


one_arr.append(0)
one_arr.append(1)


for i in range(2,41):

    zero_arr.append(zero_arr[i-1]+zero_arr[i-2])
    one_arr.append(one_arr[i-1]+one_arr[i-2])


for i in range(t):
    print(zero_arr[input_arr[i]],one_arr[input_arr[i]])
    
    

    
