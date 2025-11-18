#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    void createAccount(string name, int accNo, double bal) {
        accountHolder = name;
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: ₹" << amount << " successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: ₹" << amount << " successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void displayStatement() {
        cout << "\n--- Account Statement ---\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: ₹" << balance << endl;
    }
};

class SavingAccount : public Account {
private:
    double interestRate;

public:
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest of ₹" << interest << " added.\n";
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    void setOverdraftLimit(double limit) {
        overdraftLimit = limit;
    }

    void withdrawFromChecking(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn ₹" << amount << " successfully.\n";
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }
};

int main() {
    SavingAccount sAcc;
    CheckingAccount cAcc;

    cout << "--- Savings Account ---\n";
    sAcc.createAccount("Arjun Joshi", 101, 5000);
    sAcc.setInterestRate(5.0);
    sAcc.deposit(1000);
    sAcc.withdraw(2000);
    sAcc.addInterest();
    sAcc.displayStatement();

    cout << "\n--- Checking Account ---\n";
    cAcc.createAccount("Ranvir Mehta", 202, 3000);
    cAcc.setOverdraftLimit(2000);
    cAcc.deposit(1500);
    cAcc.withdrawFromChecking(4500);
    cAcc.displayStatement();

    return 0;
}