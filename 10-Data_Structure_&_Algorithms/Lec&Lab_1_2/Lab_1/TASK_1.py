class Node:
    def __init__(self, _empNumber, _empName , _empSalary ):
        self.empNumber = _empNumber if _empNumber >= 0 else (-1 * _empNumber)
        self.empName = _empName if _empName != None else "No Name"
        self.empSalary = _empSalary if _empSalary >= 0 else (-1 * _empSalary)
        self.next = None

# we will create a class for linked lists with a head only 
class LinkedLists:
    def __init__(self):
        self.head = None
    
    # 1- Insert Employee
    def insertEmp(self, _empNumber, _empName, _empSalary):
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

    # 2- Update Employee Data by Location
    def updateByLocation(self, _location, _empID, _empName, _empSalary):
        IsUpdated = False
        if (self.head != None):
            currentEmp = self.head 
            if (_location == 0):
                self.head.empNumber = _empID
                self.head.empName = _empName
                self.head.empSalary = _empSalary
                IsUpdated = True

            else:
                i = 0 
                while (i < _location and currentEmp != None):
                    currentEmp = currentEmp.next
                    i += 1

                if (currentEmp != None):
                    currentEmp.empNumber = _empID
                    currentEmp.empName = _empName
                    currentEmp.empSalary = _empSalary
                    IsUpdated = True

        return IsUpdated
    

    # 3- Delete by ID
    def deleteEmp(self, empNumber_to_delete):
    
        IsDeleted = False
        if (self.head != None):
            if (self.head.empNumber == empNumber_to_delete): # if the head is the node to be deleted
                self.head = self.head.next
                IsDeleted = True

            else :
                currentEmp = self.head
                while (currentEmp.next != None): # if the list is not ended yet

                    if (currentEmp.next.empNumber == empNumber_to_delete):
                        currentEmp.next = (currentEmp.next).next
                        IsDeleted = True
                        break

                    currentEmp = currentEmp.next

        return IsDeleted
    

    # 4- Update Employee Data by his/her ID
    def updateEmp(self, _empNumber, _empName, _empSalary):
        IsUpdated = False
        if (self.head != None): # if the list is not empty
            currentEmp = self.head
            while (currentEmp != None): # list is not ended yet
                if (currentEmp.empNumber == _empNumber):
                    currentEmp.empName = _empName
                    currentEmp.empSalary = _empSalary
                    IsUpdated = True
                    break
                currentEmp = currentEmp.next

        return IsUpdated
    
    # 5- Display All Employees
    def displayAll(self):
        IsEmpty = False
        if (self.head != None):
            IsEmpty = True
            currentEmp = self.head
            i = 0
            while (currentEmp != None):
                print(f"Employee {i+1}: ID : {currentEmp.empNumber}, Name : {currentEmp.empName}, Salary : {currentEmp.empSalary}")
                print("=====================================")
                i += 1
                currentEmp = currentEmp.next


        return IsEmpty
    
    # 6- Delete All Employees
    def deleteAll(self):
        IsDeleted = False
        if (self.head != None):
            self.head = None
            IsDeleted = True

        return IsDeleted
    

if __name__ == "__main__" :
    empList_1 = LinkedLists()
    empList_1.insertEmp(10, "Ahmed", 5000)
    empList_1.insertEmp(20, "Mohamed", 4000)
    empList_1.insertEmp(30, "Hassan", 3000)
    empList_1.insertEmp(40, "Israa", 10_000)
    empList_1.insertEmp(40, "Yasmin", 200)
    empList_1.insertEmp(-50,"Hager",4000)

    empList_1.displayAll()
    print("\n")
    empList_1.updateEmp(10, "Ali", 6000) # update by ID
    empList_1.displayAll()

    print("\n")

    empList_1.deleteEmp(20) # delete by ID
    empList_1.displayAll()

    print("\n")
    empList_1.updateByLocation(1, 3, "Yasmin", 7000) # update by location
    empList_1.displayAll()

    print("\n")

    empList_1.deleteAll()

    print("Program ended successfully ^-^")







