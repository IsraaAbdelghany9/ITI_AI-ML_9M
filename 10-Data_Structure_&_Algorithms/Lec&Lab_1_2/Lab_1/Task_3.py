class Node:
    def __init__(self, _empNumber, _empName , _empSalary ):
        self.empNumber = _empNumber if _empNumber >= 0 else (-1 * _empNumber)
        self.empName = _empName if _empName != None else "No Name"
        self.empSalary = _empSalary if _empSalary >= 0 else (-1 * _empSalary)
        self.next = None


# we will create a class for Queue with a head only
class empQueue:
    def __init__(self):
        self.head = None
        self.size = 10

    def enqueue(self, _empNumber, _empName, _empSalary):
        IsInserted = False
        newNode = Node(_empNumber, _empName, _empSalary)
        if self.head == None:
            self.head = newNode
            IsInserted = True
        else:
            currentEmp = self.head
            while currentEmp != None:
                if currentEmp.empNumber == _empNumber:
                    print("Employee with the same ID already exists")
                    return IsInserted  # Exit early if a duplicate is found
                if currentEmp.next == None:  # If we're at the last node
                    break
                currentEmp = currentEmp.next
            currentEmp.next = newNode
            IsInserted = True

        return IsInserted
    
    def dequeue(self):
        IsDeleted = False
        if self.head != None:
            self.head = self.head.next
            IsDeleted = True

        return IsDeleted
    

if __name__ == "__main__":
    empQueue1 = empQueue()
    empQueue1.enqueue(1, "Ahmed", 1000)
    empQueue1.enqueue(1, "Mohamed", 2000)
    
    for i in range(4):
        dequeued = empQueue1.dequeue()
        print("Employee Dequeued" if dequeued else "Queue is empty")


