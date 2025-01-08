# Stack is working in LIFO order (Last In First Out)
# Stack is implemented using list in python and tos 
# Dealing with the stack should be only using pop and push methods
# If you need to apply any other method then you should use a different data structure or use the pop and push methods to implement the required method


class stack:
    def __init__(self, size = 10):
        self.arr = []
        self.tos= 0 # top of stack # sometimes people use -1 as well
        self.size = size

    def push(self, data):
        IsPushed = False

        if (self.tos < self.size):
            self.arr.append(data)
            self.tos += 1
            IsPushed = True
        
        return IsPushed

    def pop(self):
        poped = -1 # heere I am implementing a stack of positive integers only so if the poped value is -1 then it means that the stack is empty

        if (self.tos > 0):
            poped = self.arr.pop()
            self.tos -= 1

        return poped
    
