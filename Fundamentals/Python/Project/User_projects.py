import json
import re
import emoji
from datetime import datetime
import os

# from UserLogin_rej import start_program_

class project:

    user_file = "project_data.json"
    
    def __init__(self):
        self.user_email = ""  # To link the project to the user
        self.project_Title = ""
        self.project_details = ""
        self.project_total_target = ""
        self.project_end_date = ""
        self.project_start_date = ""


    def Title_check_str(self):
        for i in range(3):
            str_in = input("Enter the project Title: ")
            if isinstance(str_in, str) and len(str_in) >= 4 and isinstance(str_in[0], str):
                print("TItle entered is valid")
                return str_in
            elif i < 2:
                print(f"Invalid title, you have {2 - i} attempts left")
            else:
                print("Invalid trial, please try again later")
                print("You have exceeded the number of attempts")
                exit()

    def check_total_target(self):
        
        for i in range(3):
            try:
                total_target = input("Enter the total target: in format like 1000 EGP")
                number , character = total_target.split()
                number = float(number)
                if len(character) == 3:
                        print("Total target entered is valid.")
                        return total_target
                
                else:
                    print("invalid please enter the total target in the correct format ,Currency should be 3 characters long.")
                    print("Example :1000 EGP")
                    print (f"you have {2 - i} attempts left")
            
            except ValueError:
                print("invalid please enter the total target in the correct format , number and 3 character long currency.")
                print("Example :1000 EGP")
                print (f"you have {2 - i} attempts left")

        print("You have exceeded the number of attempts")



    def validate_date(self):  

        for i in range(3):
            date_string = input("Enter the date in the format YYYY-MM-DD: ")
            date_format="%Y-%m-%d"
            try:  
                datetime.strptime(date_string, date_format)  
                return date_string  # Date is valid  
            except ValueError:  
                print(f"Invalid date, please try again , Date should be in the format YYYY-MM-DD")
                print(f"You have {2 - i} attempts left")

        print("You have exceeded the number of acceptable attempts.")
        return False  # Date is invalid  
    

    def save_data(self):
        try:
            with open(self.user_file, "r") as file:
                users = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            users = []  

        # Append the new user
        users.append(self.__dict__)

        # Write updated data
        with open(self.user_file, "w") as file:
            json.dump(users, file, indent=5)

        print("User data saved successfully!")



    # @classmethod
    # def get_all_projects(cls):
    #     try:
    #         with open(cls.user_file, "r") as file:
    #             users = json.load(file)
    #     except (FileNotFoundError, json.JSONDecodeError):
    #         users = []  

    #     return users

    @classmethod
    def get_all_projects(cls , user_email):
        try:
            with open(cls.user_file, "r") as file:
                projects = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            projects = []  

        # Filter projects by user email
        user_projects = []
        for project in projects:
            if project["user_email"] == user_email:
                user_projects.append(project)

        return user_projects



    @classmethod
    def erase_data(cls):
        with open(cls.user_file, "w") as file:
            pass

    def delete_project(self):
        print("please enter the project title you want to delete")
        project_title = self.Title_check_str()
        all_projects = self.get_all_projects(self.user_email)
        for project in all_projects:
            if project["user_email"] == self.user_email and project["project_Title"] == project_title:
                all_projects.remove(project)
                with open(self.user_file, "w") as file:
                    json.dump(all_projects, file, indent=5)
                print(f"Project '{project_title}' has been deleted successfully")
                return
            print(f"Project '{project_title}' not found")

    def edit_Project_data(self):
        print("please enter the project title you want to edit")
        project_title = self.Title_check_str()
        all_projects = self.get_all_projects(self.user_email)
        for project in all_projects:
            if project["user_email"] == self.user_email and project["project_Title"] == project_title:
                project["project_Title"] = input("Enter the new project title: ")
                project["project_details"] = input("Enter the new project details: ")
                project["project_total_target"] = input("Enter the new total target: ")
                project["project_start_date"] = input("Enter the new start date: ")
                project["project_end_date"] = input("Enter the new end date: ")
                with open(self.user_file, "w") as file:
                    json.dump(all_projects, file, indent=5)
                print(f"Project '{project_title}' has been updated successfully")
                return

    def search_by_end_date(self):
        print("Enter the end date you want to search for")
        end_date = self.validate_date()
        all_projects = self.get_all_projects(self.user_email)
        for project in all_projects:
            if project["project_end_date"] == end_date and project["user_email"] == self.user_email:
                print(project)
                return True
            else:
                print("The project is not found")
            


    
    def search_by_start_date(self):

        start_date = self.validate_date()
        all_projects = self.get_all_projects(self.user_email)
        for project in all_projects:
            if project["project_start_date"] == start_date and project["user_email"] == self.user_email:
                print(project)
                return True
            else:
                print("The project is not found")
                

def menu(): 
    print("Welcome to our system")
    print("Please choose one of the following options:")
    print("1- Create new project")
    print("2- Display all projects")
    print("3- Delete project")
    print("4- Edit project")
    print("5- Search by end date")
    print("6- Search by start date")
    print("7- Logout, exit the program")
    print("8- logout, Back to login page")

def clear_screen():
    input("Press Enter to continue...")
    os.system('clear')

def start_program(logged_in_user_email):

    menu()

    choice = input("Enter your choice: ")

    User1 = project()
    User1.user_email = logged_in_user_email  # Set the logged-in user's email

    

    if choice == "1":
        User1.project_Title = User1.Title_check_str()
        User1.project_details = input("Enter the project details: ")
        User1.project_total_target = User1.check_total_target()
        print("Enter the project start date")
        User1.project_start_date = User1.validate_date()
        print("Enter the project end date")
        User1.project_end_date = User1.validate_date()
        User1.save_data()
        clear_screen()

    elif choice == "2": 
        print("All projects :")

        for user in User1.get_all_projects(logged_in_user_email):
            print(user)
        
        clear_screen()

    elif choice == "3":
        print("please enter the project title you want to delete")
        User1.delete_project()
        clear_screen()
    
    elif choice == "4":
        print("please enter the project title you want to edit")
        User1.edit_Project_data()
        clear_screen()
    
    elif choice == "5":
        print("Enter the end date you want to search for")
        User1.search_by_end_date()
        clear_screen()
    
    elif choice == "6":
        print("Enter the start date you want to search for")
        User1.search_by_start_date()
        clear_screen()
    
    elif choice == "7":
        clear_screen()
        print("You have logged out successfully")
        print("Thank you for using our system")
        print("Goodbye!, see you later ^_^")
        exit()

    # elif choice == "8":
    #     start_program_()


    else:   
        print("Invalid choice")


# Main program

#start_program("israa@gmail.com")  # Replace this with the logged-in user's email
