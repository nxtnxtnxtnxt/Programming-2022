#include <iostream>
#include <string>
#include <vector>
#include <search.h>
#include <math.h>

using namespace std;

class Client {
private:
    string name_;
    string address_;
    string phone_;
public:
    Client(const string& name, const string& address, const string& phone)
        : name_(name), address_(address), phone_(phone) {}

    const string& getName() const {
        return name_;
    }

    const string& getAddress() const {
        return address_;
    }

    const string& getPhone() const {
        return phone_;
    }

};

class BankAccount {
private:
    Client client_;
    string accountNumber_;
    double balance_;
public:
    BankAccount(const Client& client, const string& accountNumber, double balance = 0.0)
        : client_(client), accountNumber_(accountNumber), balance_(balance) {}

    const Client& getClient() const {
        return client_;
    }

    const string& getAccountNumber() const {
        return accountNumber_;
    }

    double getBalance() const {
        return balance_;
    }

    void deposit(double amount) {
        balance_ += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance_) {
            return false;
        }
        balance_ -= amount;
        return true;
    }

    void display() const {
        cout << "Account Number: " << accountNumber_ << endl;
        cout << "Client Name: " << client_.getName() << endl;
        cout << "Address: " << client_.getAddress() << endl;
        cout << "Phone: " << client_.getPhone() << endl;
        cout << "Balance: " << balance_ << endl;
    }
};

int main()
{
    Client client1("John Smith", "123 Main St, Anytown, USA", "(555) 555-1234");
    Client client2("Jane Doe", "456 Elm St, Anytown, USA", "(555) 555-5678");
    Client client3("Bob Johnson", "789 Oak St, Anytown, USA", "(555) 555-9012");

    vector<BankAccount> accounts;
    accounts.push_back(BankAccount(client1, "1234567890", 1000.0));
    accounts.push_back(BankAccount(client2, "2468013579", 2000.0));
    accounts.push_back(BankAccount(client3, "9876543210", 1500.0));

    int choice;
    string name, address, accountNumber;
    double amount;
    bool found;
    cout << "Find by" << endl;
    cout << "1. Client Name" << endl;
    cout << "2. Client Address" << endl;
    cout << "3. Account Number" << endl;
    cout << "4. Leave" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter client name: ";
        cin.ignore();
        getline(cin, name);
        found = false;
        for (const auto& account : accounts) {
            if (account.getClient().getName() == name) {
                account.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No accounts found for client " << name << endl;
        }
        return 0;
    case 2:
        cout << "Enter client address: ";
        cin.ignore();
        getline(cin, address);
        found = false;
        for (const auto& account : accounts) {
            if (account.getClient().getAddress() == address) {
                account.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No accounts found for client at address " << address << endl;
        }
        return 0;
    case 3:
        cout << "Enter account number: ";
        cin.ignore();
        getline(cin, accountNumber);
        found = false;
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                account.display();
                found = true;
            }
        }
        if (!found) {
            cout << "Account not found for number " << accountNumber << endl;
        }
        return 0;
    case 4:
        cout << "Goodbye!" << endl;
        return 0;
    default:
        cout << "Invalid choice" << endl;
    }
    return 0;
}
