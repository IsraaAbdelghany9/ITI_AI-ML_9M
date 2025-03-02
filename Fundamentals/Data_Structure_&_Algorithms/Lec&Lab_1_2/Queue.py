# Queue is working on FIFO order (First In First Out)
# There is 2 types of queues:
# 1. Linear Queue : The elements are moving in a linear way
# 2. Circular Queue : The head(cashier) are moving in a circular way
# My implementation is for the linear queue


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, data):
        IsAdded = False
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            IsAdded = True
            
        else:
            self.tail.next = new_node
            self.tail = new_node
            IsAdded = True

        return IsAdded

    def dequeue(self):
        poped = -1
        if self.head != None:
            poped = self.head.next
            self.head = self.head.next
            if (self.head == None):
                self.tail = None
            
        return poped