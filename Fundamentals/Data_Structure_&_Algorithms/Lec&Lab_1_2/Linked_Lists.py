class Node:
    def __init__(self):
        self.prev = None
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data, loc):
        new_node = Node()
        if self.head is None: # if the list is empty
            self.head = new_node
            self.tail = new_node

        if(loc == 0): # insert at the beginning of the list
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node

        elif(loc == -1): # insert at the end of the list
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node

        else: # insert at a specific location
            i = 0
            current = self.head
            while i < loc and current != None:
                current = current.next
                i += 1
            if (current == self.tail or current == None):
                new_node.prev = self.tail
                self.tail.next = new_node
                self.tail = new_node


    def delete(self, loc):
        IsDeleted = False
        if self.head != None:
            if(loc == 0):
                if (self.head == self.tail):
                    self.head = None
                    self.tail = None

                else:
                    self.head = self.head.next
                    self.head.prev = None

            elif(loc == -1):
                if (self.head == self.tail):
                    self.head = None
                    self.tail = None

                else:
                    self.tail = self.tail.prev
                    self.tail.next = None

            else:
                i = 0
                current = self.head
                while i < loc and current != None:
                    current = current.next
                    i += 1
                if current != None:
                    current.prev.next = current.next
                    current.next.prev = current.prev
            
            IsDeleted = True

        return IsDeleted







        

    