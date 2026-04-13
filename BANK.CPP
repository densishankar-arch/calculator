#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Bank {
private:
    int accNo;
    char name[50];
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit() {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw() {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (amt > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amt;
            cout << "Amount Withdrawn Successfully!\n";
        }
    }

    void display() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }
};

int main() {
    Bank b;
    int choice;

    do {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: b.createAccount(); break;
            case 2: b.deposit(); break;
            case 3: b.withdraw(); break;
            case 4: b.display(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}