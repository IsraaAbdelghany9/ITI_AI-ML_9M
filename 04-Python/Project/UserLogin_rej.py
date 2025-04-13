import re
import json
import User_projects
import os


class UserRegistration:

    user_file = "Users_data.json"

    def __init__(self):
        self.Fname = ""
        self.Lname = ""
        self.email = ""
        self.password = ""
        self.comfirmed_password = ""
        self.Mobile_number = ""
        self.projects = []  # Attribute to hold associated projects


    def Fname_check_str(self):
        for i in range(3):
            str_in = input("Enter your first Name: ")
            if isinstance(str_in, str) and len(str_in) >= 4 and isinstance(str_in[0], str):
                print("First name entered is valid")
                return str_in
            elif i < 2:
                print(f"Invalid name, you have {2 - i} attempts left")
            else:
                print("Invalid name, please try again later")
                print("You have exceeded the number of attempts")
                exit()

    def Lname_check_str(self):
        for i in range(3):
            str_in = input("Enter your last Name: ")
            if isinstance(str_in, str) and len(str_in) >= 4 and isinstance(str_in[0], str):
                print("Last name entered is valid")
                return str_in
            elif i < 2:
                print(f"Invalid name, you have {2 - i} attempts left")
            else:
                print("Invalid name, please try again later")
                print("You have exceeded the number of attempts")
                exit()

    def validate_email(self):
        for i in range(3):
            email = input("Enter your email: ")
            if re.match(r"[^@]+@[^@]+\.[^@]+", email):
                print("Valid email")
                return email
            elif i < 2:
                print(f"Invalid email, you have {2 - i} attempts left")
            else:
                print("Invalid email, please try again later")
                print("You have exceeded the number of attempts")
                exit()

    def check_password(self):
        for i in range(3):
            password = input("Enter your password > 4 characters or numbers: ")
            if isinstance(password, str) and len(password) >= 4:
                print("Password entered is valid")
                return password
            elif i < 2:
                print(f"Invalid password, you have {2 - i} attempts left")
            else:
                print("Invalid password, please try again later")
                print("You have exceeded the number of attempts")
                exit()

    def comfirm_password(self, password):
        for i in range(3):
            confirmed_password = input("Confirm your password: ")
            if confirmed_password == password:
                print("Password confirmation successful")
                return confirmed_password
            elif i < 2:
                print(f"Passwords do not match, you have {2 - i} attempts left")
            else:
                print("Password confirmation failed")
                print("You have exceeded the number of attempts")
                exit()

    def Check_Mobile_number(self):
        for i in range(3):
            mobile_number = input("Enter your mobile number (Egyptian format): ")
            if re.match(r"^01[0-9]{9}$", mobile_number):
                print("Valid mobile number")
                return mobile_number
            elif i < 2:
                print(f"Invalid mobile number, you have {2 - i} attempts left")
            else:
                print("Invalid mobile number, please try again later")
                print("You have exceeded the number of attempts")
                exit()        

    def userRegFun(self) :

        print("Registration process is started")
        self.Fname = self.Fname_check_str()
        self.Lname = self.Lname_check_str()
        self.email = self.validate_email()
        self.password = self.check_password()
        self.comfirmed_password = self.comfirm_password(self.password)
        self.Mobile_number = self.Check_Mobile_number()
        self.save_data()


    def userLoginFun(self):
        print("Login process is started")
        all_users = self.get_all_users()

        for attempt in range(3):  # Allow up to 3 attempts
            email = self.validate_email()
            matching_user = None

            # Check if the entered email matches any user's email (case-sensitive)
            for user in all_users:
                if email == user["email"]:  # Case-sensitive match
                    matching_user = user
                    break

            if matching_user:
                # If email is found, allow up to 3 password attempts
                for _ in range(3):
                    password = self.check_password()
                    if password == matching_user["password"]:  # Exact password match
                        print("Login is done successfully ^_^")
                        while True:
                            User_projects.start_program(matching_user['email'])
                    else:
                        print("Invalid password, try again.")
                print("You have exceeded the maximum password attempts.")
                return False
            else:
                print(f"The email you entered is not available, you have {2 - attempt} attempts left")

        print("Login failed >_<")
        return False


    def save_data(self):
        try:
            try:
                # Read existing data
                with open(self.user_file, "r") as file:
                    users = json.load(file)
            except (FileNotFoundError, json.JSONDecodeError):
                users = []  # Initialize as an empty list if the file doesn't exist or is corrupted

            # Append the new user
            users.append(self.__dict__)

            # Write updated data
            with open(self.user_file, "w") as file:
                json.dump(users, file, indent=4)

            print("User data saved successfully!")
        except Exception as e:
            print(f"An error occurred while saving data: {e}")
        
    @classmethod
    def get_all_users(cls):
        try:
            file = open(cls.user_file, "r")
            users = json.load(file)
            file.close()
            # with open(cls.user_file, "r") as file:
            #     users = json.load(file)
        except (FileNotFoundError, json.JSONDecodeError):
            users = []  

        return users
    
    @classmethod
    def erase_data(cls):
        with open(cls.user_file, "w") as file:
            pass

def printMenu ():
    print("Please choose one of the following options:")
    print("1- Register")
    print("2- Login")
    print("3- Exit")

#dealing with the user input
def start_program_():
    print("Welcome to our system")
    clear_screen()
    printMenu()
    choice = input("Enter your choice: ")
    if choice == "1":
        User1.userRegFun()
        clear_screen()
    elif choice == "2":
        User1.userLoginFun()
        clear_screen()

    elif choice == "3":
        exit()

    else:
        print("Invalid choice")


def clear_screen():
    input("Press Enter to continue...")
    os.system('clear')

# Main program


while True:
    User1 = UserRegistration()
    start_program_()





