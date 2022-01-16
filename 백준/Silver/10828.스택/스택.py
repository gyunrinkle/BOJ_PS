import sys

ERROR=-1

class Stack:

    def __init__(self):
        self.top=-1
        self.stack_list=[]
    
    def get_size(self):
        return self.top+1
    
    #only for printing size
    def size(self):
        print(self.get_size())
        
    def is_empty(self):
        if self.top==-1:
            return True
        else:
            return False
    
    #only for printing whether the stack is empty
    def empty(self):
        if self.is_empty():
            print(1)
        else:
            print(0)

    #func top()
    def print_top(self):
        if self.is_empty():
            print(ERROR)
        else:
            print(self.stack_list[self.top])

    def push(self,data):
        self.stack_list.append(data)
        self.top+=1
    
    def pop(self):
        if self.is_empty():
            print(ERROR)
        else:
            print(self.stack_list.pop())
            self.top-=1
    


def ExecuteInstruction(comm,stck):
    #print(comm)

    inst_dic={
        'push':stck.push,
        'pop':stck.pop,
        'size':stck.size,
        'empty':stck.empty,
        'top':stck.print_top
    }

    if comm[0]=='push':
        inst_dic[comm[0]](comm[1])
    else:
        inst_dic[comm[0]]()

    

    

def main():

    stack=Stack()
    n=int(sys.stdin.readline())
    #print(n,'instructions will be executed')
    for i in range(n):
        comm=sys.stdin.readline().split()
        ExecuteInstruction(comm,stack)


if __name__=='__main__':
    main()