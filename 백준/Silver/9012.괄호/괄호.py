
def vps(ps):

    stck=[]
    n=len(ps)
    for i in range(n):

        if len(stck)==0:
            stck.append(ps[i])
        else:
            tmp_str=stck[-1]+ps[i]
            if tmp_str =='()':
                stck.pop()
            else:
                stck.append(ps[i])

    if len(stck)==0:
        return 'YES'
    else:
        return 'NO'

t=int(input())
output=[]

for i in range(t):
    inpt=input()
    output.append(vps(inpt))

for i in range(t):
    print(output[i])

    
    