# Stack is working with the LIFO principle. (Last In First Out)
class Node :
    def __init__(self, _data = 0):
        self.data = _data if _data >= 0 else (-1 * _data)
        self.prev = None

class stack:
    def __init__(self):
        self.tail = None
        
    def push(self, data):
        new_node = Node(data)
        if self.tail == None:
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail = new_node


    def pop(self):
        poped = -1 # so that if the function returns -1, it means that the stack is empty
        if self.tail != None:
            poped = self.tail.data
            self.tail = self.tail.prev

        return poped
        

if __name__ == "__main__":
    stack1 = stack()
    stack1.push(5)
    stack1.push(10)
    stack1.push(15)
    
    for i in range(4):
        poped = stack1.pop()
        print( poped if poped != -1 else "Stack is empty")

