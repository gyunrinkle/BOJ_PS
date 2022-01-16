import sys

class Queue:

    def __init__(self):
        self.items = []
        self.head = 0
    
    def is_empty(self):
        if self.head == len(self.items):
            self.__init__()
            return True
        return False

    def push(self, n):
        self.items.append(n)
    
    def size(self):
        if self.is_empty():
            return 0
        return len(self.items) - self.head
    
    def pop(self):
        if self.is_empty():
            return -1
        
        tmp = self.items[self.head]
        self.head += 1
        return tmp
    
    def front(self):
        if self.is_empty():
            return -1

        return self.items[self.head]
    
    def back(self):
        if self.is_empty():
            return -1
        return self.items[len(self.items) - 1]

_queue = Queue()

n = int(sys.stdin.readline())

for _ in range(n):

    cmd = sys.stdin.readline().split()

    if cmd[0] == 'push':
        _queue.push(int(cmd[1]))
        continue
    
    if cmd[0] == 'pop':
        print(_queue.pop())
        continue
    
    if cmd[0] == 'size':
        print(_queue.size())
        continue
    
    if cmd[0] == 'empty':
        if _queue.is_empty():
            print(1)
        else:
            print(0)
        
        continue
    
    if cmd[0] == 'front':
        print(_queue.front())
        continue
    
    if cmd[0] == 'back':
        print(_queue.back())
        continue
