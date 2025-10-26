#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    string id;

public:
    Person(string n, string i) : name(n), id(i) {}
    virtual void showInfo() const { 
        cout << "Name: " << name << "\nID: " << id << endl;
    }
};

// Derived class: User
class User : public Person {
private:
    string pin;
    double balance;

public:
    User(string n, string i, string p, double b) : Person(n, i), pin(p), balance(b) {}

    void showInfo() const override { 
        cout << "User Info:\n";
        cout << "Name: " << name << "\nID: " << id << "\nBalance: Rs" << balance << endl;
    }

    bool verifyPin(string enteredPin) {
        return pin == enteredPin;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs" << amount << ". New Balance: Rs" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn Rs" << amount << ". Remaining Balance: Rs" << balance << endl;
        }
    }

    void changeName(string newName) {
        if (!newName.empty()) {
            newName[0] = toupper(newName[0]);
            for (size_t i = 1; i < newName.length(); i++)
                newName[i] = tolower(newName[i]);
        }
        name = newName;
        cout << "Name changed successfully to " << name << endl;
    }

    void resetBalance(double newBalance) {
        balance = newBalance;
        cout << "Balance reset to Rs" << balance << endl;
    }

    string getID() const { return id; }
};

// Derived class: Admin
class Admin : public Person {
public:
    Admin(string n, string i) : Person(n, i) {}

    void showInfo() const override {  
        cout << "Admin Info:\n";
        cout << "Name: " << name << "\nID: " << id << endl;
    }

    void showAllUsers(const vector<User> &users) const {
        cout << "\n---All Users---\n";
        for (const auto &u : users) {
            u.showInfo();
            cout << endl;
        }
    }

    void resetUserBalance(vector<User> &users, string userID, double newBalance) {
        for (auto &u : users) {
            if (u.getID() == userID) {
                u.resetBalance(newBalance);
                return;
            }
        }
        cout << "User not found!\n";
    }
};

int main() {
    vector<User> users;
    users.push_back(User("Jasleen", "U1001", "1234", 5000));
    users.push_back(User("Gita", "U1002", "5678", 3800));
    users.push_back(User("Ram", "U1003", "9012", 4000));
    users.push_back(User("Sita", "U1004", "3456", 2900));

    Admin admin("Manager", "A001");

    int userType;
    cout << "Welcome to ATM Simulator!\n";
    cout << "Login as User(1) or Admin(2): ";
    cin >> userType;

    if (userType == 1) {
        string userID, pin;
        cout << "Enter User ID: ";
        cin >> userID;
        User *currentUser = nullptr;
        for (auto &u : users) {
            if (u.getID() == userID) {
                currentUser = &u;
                break;
            }
        }
        if (!currentUser) {
            cout << "User not found!\n";
            return 0;
        }

        cout << "Enter PIN: ";
        cin >> pin;
        if (!currentUser->verifyPin(pin)) {
            cout << "Incorrect PIN!\n";
            return 0;
        }

        int choice;
        do {
            cout << "\n---ATM Menu---\n";
            cout << "1. Show Info\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Change Name\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                currentUser->showInfo();
                break;
            case 2: {
                double amt;
                cout << "Enter amount to deposit: ";
                cin >> amt;
                currentUser->deposit(amt);
                break;
            }
            case 3: {
                double amt;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                currentUser->withdraw(amt);
                break;
            }
            case 4: {
                string newName;
                cout << "Enter new name: ";
                cin >> newName;
                currentUser->changeName(newName);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 5);

    } else if (userType == 2) {
        int choice;
        do {
            cout << "\n---Admin Menu---\n";
            cout << "1. Show all users\n";
            cout << "2. Reset a user's balance\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                admin.showAllUsers(users);
                break;
            case 2: {
                string uid;
                double newBal;
                cout << "Enter User ID to reset balance: ";
                cin >> uid;
                cout << "Enter new balance: ";
                cin >> newBal;
                admin.resetUserBalance(users, uid, newBal);
                break;
            }
            case 3:
                cout << "Exiting Admin menu.\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 3);
    }

    return 0;
}   
