import json

class Queue :
    queue_data_file = "queue_data.json"

    def __init__(self, name , size) :
        self.name = name
        self.tos = -1
        self.queue = [None] * size
        self.size = size


    def is_empty(self):
        if self.tos == -1:
            return True
        else:
            return False

    def is_full(self):
        if self.tos == self.size - 1:
            return True
        else:
            return False
                
    
    def pop(self):
        try:
            element = self.queue[0]  
            #print("element popped is ", element)
            # self.display()
            self.queue[0] = None  ###Important Note  : this is to clear the old position

            for i in range(1, self.tos + 1):
                self.queue[i - 1] = self.queue[i]
                self.queue[i] = None
                
            self.tos -= 1 
            return element
        
        except IndexError :
            print("QueueOutOfRangeException, Queue is empty now!")
        

    def push(self, element):

        try :
            #print("element pushed is ", element)
            self.tos += 1
            self.queue[self.tos] = element
        except IndexError :
            print("QueueOutOfRangeException, Queue is full now!")


    def display(self) :
        try:
            if self.is_empty() :
                print( "Queue is empty" )
            else :
                for i in range(self.tos + 1) :
                    print( self.queue[i] )
        except IndexError :
            print("QueueOutOfRangeException")

    # def saveQueue(self):
    #     try:
    #         with open(self.queue_data_file, "r") as file:
    #             queues = json.load(file)

    #     except (FileNotFoundError, json.JSONDecodeError):
    #         queues = []  

    #     # Append the new user
    #     for queue in queues:
    #         if not (self.queue["name"] in queues ):
    #             queues.append(self.__dict__)

    #     # Write updated data
    #     with open(self.queue_data_file, "w") as file:
    #         json.dump(queues, file, indent=4)

    #     print("Queue data saved successfully!")
    def saveQueue(self):
        try:
            with open(self.queue_data_file, "r") as file:
                queues = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            queues = []  

        # Append the new queue if it doesn't exist
        if not any(queue["name"] == self.name for queue in queues): #any() returns True if any element is True, and False if all elements are False.
            queues.append(self.__dict__)

        # Write updated data back to the file
        with open(self.queue_data_file, "w") as file:
            json.dump(queues, file, indent=4)

        print("Queue data saved successfully!")

    @classmethod
    def getAllQueues(cls ):
        try:
            with open(cls.queue_data_file, "r") as file:
                queues = json.load(file)

            return queues
        except (FileNotFoundError, json.JSONDecodeError):
            queues = []  

    def search_by_Name(self):

        all_queues = self.getAllQueues()
        for queue in all_queues:
            if queue["name"] == self.name:
                print(queue)
                return True
            else:
                print("The queue is not found") 

q1 = Queue("q1",5)

q1.push(1)
q1.push(2)
q1.push(3)
q1.push(4)
q1.push(5)

q1.saveQueue()


print(q1.getAllQueues())
# q1.display()

q1.pop()
q1.pop()
q1.pop()

# q1.display()


q1.pop()
q1.pop()

q1.display()

q1.search_by_Name()