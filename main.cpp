#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// -------------------- User Class --------------------
class User {
public:
    string username;
    string pin;
    double balance;

    User() {}
    User(string u, string p, double b) : username(u), pin(p), balance(b) {}

    void displayBalance() const {
        cout << "Your current balance: " << balance << endl;
    }

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited successfully! New balance: " << balance << endl;
    }

    void withdraw(double amt) {
        if (amt > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amt;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }
};

// -------------------- ATM System Class --------------------
class ATMSystem {
private:
    vector<User> users;

public:
    ATMSystem() {
        loadUsers();
    }

    void loadUsers() {
        users.clear();
        ifstream file("users.txt");
        if (!file) return; // if file not found

        User u;
        while (file >> u.username >> u.pin >> u.balance) {
            users.push_back(u);
        }
        file.close();
    }

    void saveUsers() {
        ofstream file("users.txt");
        for (auto &u : users) {
            file << u.username << " " << u.pin << " " << u.balance << endl;
        }
        file.close();
    }

    int findUser(const string &uname, const string &pin) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].username == uname && users[i].pin == pin)
                return i;
        }
        return -1;
    }

    void registerUser() {
        string uname, pin;
        double initialDeposit;

        cout << "\n=== Create New Account ===\n";
        cout << "Enter new username: ";
        cin >> uname;

        for (auto &u : users) {
            if (u.username == uname) {
                cout << "Username already exists! Try another.\n";
                return;
            }
        }

        cout << "Set 4-digit PIN: ";
        cin >> pin;
        cout << "Enter initial deposit: ";
        cin >> initialDeposit;

        users.push_back(User(uname, pin, initialDeposit));
        saveUsers();

        cout << "Account created successfully!\n";
    }

    void atmMenu(int idx) {
        int choice;
        do {
            cout << "\n----- ATM Menu -----\n";
            cout << "1. Balance Inquiry\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    users[idx].displayBalance();
                    break;
                case 2: {
                    double amt;
                    cout << "Enter deposit amount: ";
                    cin >> amt;
                    users[idx].deposit(amt);
                    saveUsers();
                    break;
                }
                case 3: {
                    double amt;
                    cout << "Enter withdrawal amount: ";
                    cin >> amt;
                    users[idx].withdraw(amt);
                    saveUsers();
                    break;
                }
                case 4:
                    cout << "Logging out...\n";
                    saveUsers();
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }

    void login() {
        string uname, pin;
        cout << "\nEnter Username: ";
        cin >> uname;
        cout << "Enter PIN: ";
        cin >> pin;

        loadUsers();
        int idx = findUser(uname, pin);
        if (idx != -1) {
            cout << "\nLogin Successful!\n";
            atmMenu(idx);
        } else {
            cout << "Invalid Username or PIN!\n";
        }
    }

    void start() {
        int choice;
        do {
            cout << "\n==== Welcome to ATM ====\n";
            cout << "1. Login\n";
            cout << "2. Register (New User)\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    registerUser();
                    break;
                case 3:
                    cout << "Exiting ATM... Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 3);
    }
};

// -------------------- Main Function --------------------
int main() {
    ATMSystem atm;
    atm.start();
    return 0;
}
