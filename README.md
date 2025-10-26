# 💳 ATM Simulator (C++) – Console Based Project

## 📖 Overview
The ATM Simulator is a C++ based console application designed to emulate the basic functionalities of a real-world Automated Teller Machine (ATM). This project leverages Object-Oriented Programming (OOP) concepts such as inheritance, polymorphism, encapsulation, and access specifiers (private, protected, public), alongside string manipulation techniques, to provide a robust, interactive, and user-friendly simulation of banking operations.
The main objective of this project is to provide a virtual environment where users can perform typical ATM operations such as checking account information, depositing money, withdrawing funds, and updating personal details, while administrators can manage user accounts efficiently. It demonstrates how OOP principles can be applied to build modular, maintainable, and scalable software solutions.

---

## 🧠 Functionalities

1.	User Operations:
o	Login Verification: Users can log in using their unique ID and PIN, ensuring secure access to their account.
o	Account Information Display: Users can view their name, ID, and current account balance.
o	Deposit Funds: Users can deposit money into their account, with the system updating the balance instantly.
o	Withdraw Funds: Users can withdraw money, with balance validation to prevent overdraft.
o	Change Name: Users can update their account name using proper string formatting to maintain consistency.
2.	Administrator Operations:
o	View All Users: Admin can access information of all registered users to monitor account details.
o	Reset User Balance: Admin has the privilege to reset or modify the balance of any user account.
o	Secure Access: Admin login is separate from users, ensuring controlled access to sensitive operations.


---

## 🧩 Technologies Used

C++ Programming language:

C++ is used as the primary programming language for developing the ATM Simulator. It supports Object-Oriented Programming (OOP) concepts such as inheritance, polymorphism, and encapsulation, which are essential for modeling real-world entities like users and administrators. C++ also allows efficient string manipulation and structured program development, making it suitable for building console-based simulations.

GDB Compiler:

GDB is used to compile, debug, and execute the C++ program. It helps in identifying and fixing syntax errors, runtime errors, and logical errors. The compiler ensures the code is translated into executable machine code and allows developers to run the program step by step for testing and verification.


---

## 🧱 System Design
The ATM Simulator is designed to replicate the core functionalities of a real-world ATM using a modular and object-oriented approach. The system is divided into multiple components, each responsible for a specific functionality, ensuring scalability, maintainability, and clarity.
## 1. Architecture
The system follows a console-based, menu-driven architecture, where the user interacts with the application via input commands. It has two main modules:
•	User Module: Handles all operations related to regular users.
•	Admin Module: Handles administrative operations and management of user accounts.
The modules interact with the core data structures that store user information such as name, ID, PIN, and balance.
## 2. Class Design
The system uses Object-Oriented Programming (OOP) concepts to model real-world entities:
1.	Person (Base Class)
o	Attributes: name, id
o	Function: showInfo() (virtual function) to display personal information.
o	Purpose: Acts as a parent class for both users and administrators, promoting code reuse.
2.	User (Derived Class)
o	Attributes: pin, balance
o	Functions:
o	verifyPin() – to validate login credentials
o	deposit() – to add money to account
o	withdraw() – to withdraw money from account
o	changeName() – to update user name
o	resetBalance() – to reset account balance (admin use)
o	Purpose: Represents a normal ATM user and handles all user-specific operations.
## 3.	Admin (Derived Class)
o	Functions:
o	showAllUsers() – displays information of all users
o	resetUserBalance() – modifies the balance of a specific user
o	Purpose: Represents the administrator with elevated privileges to manage user accounts.
3. Interaction Flow
1.	Login Process:
o	The system prompts the user to select login as either User or Admin.
o	For users, credentials (ID and PIN) are verified.
o	Admin login is separate and secure.
2.	User Operations:
o	Once logged in, the user can view account details, deposit or withdraw funds, and update their name.
3.	Admin Operations:
o	The admin can view all users, reset user balances, and ensure proper account management.


## Sample output

<img width="623" height="368" alt="image" src="https://github.com/user-attachments/assets/0d0dfa21-8e94-45d7-93a9-cd090c0fbce9" />
<img width="622" height="389" alt="image" src="https://github.com/user-attachments/assets/eb94cdb9-48d9-4e05-9eb2-f99c83d45e92" />
<img width="623" height="400" alt="image" src="https://github.com/user-attachments/assets/83154112-ee9a-48ce-a0d4-b94533e89592" />


## Future Enhancements

-- Encrypt PINs before storing
-- Add transaction history
-- Implement admin access for account management
-- Connect with SQL database for large-scale systems




