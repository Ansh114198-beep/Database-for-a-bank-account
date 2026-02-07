#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// BankAccount class for storing account information
class BankAccount {
private:
    string name;
    long long accountNo;
    string accountType;
    double balance;

public:
    // Default Constructor
    BankAccount() {
        cout << "[Default Constructor Called]" << endl;
        name = "";
        accountNo = 0;
        accountType = "";
        balance = 0.0;
    }

    // Parameterized Constructor
    BankAccount(string n, long long accNo, string type, double bal) {
        cout << "[Parameterized Constructor Called]" << endl;
        name = n;
        accountNo = accNo;
        accountType = type;
        balance = bal;
    }

    // Copy Constructor
    BankAccount(const BankAccount& other) {
        cout << "[Copy Constructor Called]" << endl;
        name = other.name;
        accountNo = other.accountNo;
        accountType = other.accountType;
        balance = other.balance;
    }

    // Destructor
    ~BankAccount() {
        cout << "[Destructor Called for Account: " << name << "]" << endl;
    }

    // Member function to input data using cin
    void inputData() {
        cout << "\n--- Input Account Information ---" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Account Number: ";
        cin >> accountNo;
        cout << "Enter Account Type (Savings/Checking/Business): ";
        cin.ignore();
        getline(cin, accountType);
        cout << "Enter Balance: ";
        cin >> balance;
    }

    // Member function to output data using cout
    void outputData() const {
        cout << "Name: " << name << " | Account No: " << accountNo 
             << " | Type: " << accountType << " | Balance: " << fixed 
             << setprecision(2) << balance << endl;
    }

    // Friend function for output using << operator
    friend ostream& operator<<(ostream& out, const BankAccount& account);

    // Friend function for input using >> operator
    friend istream& operator>>(istream& in, BankAccount& account);

    // Setter functions
    void setName(string n) { name = n; }
    void setAccountNo(long long accNo) { accountNo = accNo; }
    void setAccountType(string type) { accountType = type; }
    void setBalance(double bal) { balance = bal; }

    // Getter functions
    string getName() const { return name; }
    long long getAccountNo() const { return accountNo; }
    string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid amount or insufficient balance!" << endl;
        }
    }
};

// Overload << operator for output
ostream& operator<<(ostream& out, const BankAccount& account) {
    out << "Name: " << account.name << " | Account No: " << account.accountNo 
        << " | Type: " << account.accountType << " | Balance: $" << fixed 
        << setprecision(2) << account.balance;
    return out;
}

// Overload >> operator for input
istream& operator>>(istream& in, BankAccount& account) {
    cout << "\n--- Input Account Information (Using >> operator) ---" << endl;
    cout << "Enter Name: ";
    in.ignore();
    getline(in, account.name);
    cout << "Enter Account Number: ";
    in >> account.accountNo;
    cout << "Enter Account Type: ";
    in.ignore();
    getline(in, account.accountType);
    cout << "Enter Balance: ";
    in >> account.balance;
    return in;
}

// Function to search account by name
int searchAccountByName(BankAccount accounts[], int totalAccounts, string searchName) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].getName() == searchName && accounts[i].getName() != "") {
            return i;
        }
    }
    return -1;
}

// Function to check if slot is empty
bool isEmptySlot(BankAccount& account) {
    return account.getName() == "";
}

// Function to display account details
void displayAccountDetails(BankAccount& account) {
    cout << "\n========== ACCOUNT DETAILS ==========" << endl;
    cout << "Name: " << account.getName() << endl;
    cout << "Account Number: " << account.getAccountNo() << endl;
    cout << "Account Type: " << account.getAccountType() << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
    cout << "====================================" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "  BANK ACCOUNT DATABASE SYSTEM" << endl;
    cout << "========================================" << endl;

    // Array to store 10 bank accounts (using default constructor)
    BankAccount accounts[10];

    int choice;
    cout << "\n========== INPUT MENU ==========" << endl;
    cout << "Choose how to input 10 accounts:" << endl;
    cout << "1. Method 1: Using member function inputData()" << endl;
    cout << "2. Method 2: Using overloaded >> operator" << endl;
    cout << "3. Method 3: Using parameterized constructor (manual entry)" << endl;
    cout << "4. Auto-populate with sample data" << endl;
    cout << "================================" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n========== METHOD 1: INPUT USING MEMBER FUNCTIONS ==========\n" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "\n[Account " << (i + 1) << "/10]" << endl;
            accounts[i].inputData();
        }
    } 
    else if (choice == 2) {
        cout << "\n========== METHOD 2: INPUT USING OVERLOADED >> OPERATOR ==========\n" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "\n[Account " << (i + 1) << "/10]" << endl;
            cin >> accounts[i];
        }
    }
    else if (choice == 3) {
        cout << "\n========== METHOD 3: MANUAL ENTRY WITH VALIDATORS ==========\n" << endl;
        for (int i = 0; i < 10; i++) {
            string name, type;
            long long accNo;
            double balance;

            cout << "\n--- Account " << (i + 1) << " ---" << endl;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            
            cout << "Enter Account Number: ";
            cin >> accNo;
            
            cout << "Enter Account Type (Savings/Checking/Business): ";
            cin.ignore();
            getline(cin, type);
            
            cout << "Enter Balance: ";
            cin >> balance;

            BankAccount tempAccount(name, accNo, type, balance);
            accounts[i] = tempAccount;
        }
    }
    else {
        cout << "\n========== AUTO-POPULATED WITH SAMPLE DATA ==========\n" << endl;
        accounts[0] = BankAccount("John Smith", 1001001, "Savings", 15000.50);
        accounts[1] = BankAccount("Alice Johnson", 1002001, "Checking", 22500.75);
        accounts[2] = BankAccount("Robert Wilson", 1003001, "Business", 50000.00);
        accounts[3] = BankAccount("Emma Thompson", 1004001, "Savings", 18750.25);
        accounts[4] = BankAccount("David Miller", 1005001, "Checking", 35000.00);
        accounts[5] = BankAccount("Lisa Anderson", 1006001, "Business", 65000.75);
        accounts[6] = BankAccount("Michael Johnson", 1007001, "Checking", 45000.50);
        accounts[7] = BankAccount("Sarah Williams", 1008001, "Savings", 32500.75);
        accounts[8] = BankAccount("James Brown", 1009001, "Business", 95000.00);
        accounts[9] = BankAccount("Emily Davis", 1010001, "Savings", 28750.25);
        cout << "Sample data loaded successfully!" << endl;
    }

    // Interactive Account Management System
    int accountCount = 10;
    int menuChoice;

    do {
        cout << "\n========================================" << endl;
        cout << "  ACCOUNT MANAGEMENT MENU" << endl;
        cout << "========================================" << endl;
        cout << "1. View All Accounts" << endl;
        cout << "2. Search Account by Name" << endl;
        cout << "3. View Account Details" << endl;
        cout << "4. Add New Account" << endl;
        cout << "5. Update Account Information" << endl;
        cout << "6. Deposit Money" << endl;
        cout << "7. Withdraw Money" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> menuChoice;

        if (menuChoice == 1) {
            // View all accounts
            cout << "\n========== ALL ACCOUNTS ==========" << endl;
            cout << left << setw(3) << "No" << setw(20) << "Name" << setw(15) << "Account No" 
                 << setw(15) << "Type" << setw(15) << "Balance" << endl;
            cout << "=============================================================" << endl;
            int count = 0;
            for (int i = 0; i < accountCount; i++) {
                if (!isEmptySlot(accounts[i])) {
                    cout << left << setw(3) << (count + 1) << setw(20) << accounts[i].getName() 
                         << setw(15) << accounts[i].getAccountNo() 
                         << setw(15) << accounts[i].getAccountType() 
                         << setw(15) << fixed << setprecision(2) << accounts[i].getBalance() << endl;
                    count++;
                }
            }
            if (count == 0) {
                cout << "No accounts found!" << endl;
            }
        }
        else if (menuChoice == 2) {
            // Search account by name
            string searchName;
            cout << "\nEnter name to search: ";
            cin.ignore();
            getline(cin, searchName);
            
            int index = searchAccountByName(accounts, accountCount, searchName);
            if (index != -1) {
                cout << "\n[Account Found at Position " << (index + 1) << "]" << endl;
                displayAccountDetails(accounts[index]);
            } else {
                cout << "\n[Account NOT found!]" << endl;
            }
        }
        else if (menuChoice == 3) {
            // View account details
            cout << "\nEnter account position (1-" << accountCount << "): ";
            int pos;
            cin >> pos;
            if (pos >= 1 && pos <= accountCount && !isEmptySlot(accounts[pos - 1])) {
                displayAccountDetails(accounts[pos - 1]);
            } else {
                cout << "Invalid position or empty account!" << endl;
            }
        }
        else if (menuChoice == 4) {
            // Add new account
            int findEmpty = -1;
            for (int i = 0; i < 10; i++) {
                if (isEmptySlot(accounts[i])) {
                    findEmpty = i;
                    break;
                }
            }
            
            if (findEmpty == -1) {
                cout << "\nDatabase is full! Maximum 10 accounts allowed." << endl;
            } else {
                string name, type;
                long long accNo;
                double balance;
                
                cout << "\n--- Add New Account ---" << endl;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Account Type (Savings/Checking/Business): ";
                cin.ignore();
                getline(cin, type);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                
                accounts[findEmpty] = BankAccount(name, accNo, type, balance);
                cout << "[Account added successfully at position " << (findEmpty + 1) << "]" << endl;
            }
        }
        else if (menuChoice == 5) {
            // Update account information
            string searchName;
            cout << "\nEnter account name to update: ";
            cin.ignore();
            getline(cin, searchName);
            
            int index = searchAccountByName(accounts, accountCount, searchName);
            if (index != -1) {
                cout << "\n--- Update Account ---" << endl;
                cout << "1. Update Name" << endl;
                cout << "2. Update Account Type" << endl;
                cout << "3. Update Balance" << endl;
                cout << "Enter choice: ";
                int updateChoice;
                cin >> updateChoice;
                
                if (updateChoice == 1) {
                    string newName;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, newName);
                    accounts[index].setName(newName);
                    cout << "Name updated successfully!" << endl;
                } else if (updateChoice == 2) {
                    string newType;
                    cout << "Enter new account type: ";
                    cin.ignore();
                    getline(cin, newType);
                    accounts[index].setAccountType(newType);
                    cout << "Account type updated!" << endl;
                } else if (updateChoice == 3) {
                    double newBalance;
                    cout << "Enter new balance: ";
                    cin >> newBalance;
                    accounts[index].setBalance(newBalance);
                    cout << "Balance updated!" << endl;
                }
            } else {
                cout << "\n[Account NOT found!]" << endl;
            }
        }
        else if (menuChoice == 6) {
            // Deposit money
            string searchName;
            cout << "\nEnter account name for deposit: ";
            cin.ignore();
            getline(cin, searchName);
            
            int index = searchAccountByName(accounts, accountCount, searchName);
            if (index != -1) {
                double amount;
                cout << "Enter deposit amount: $";
                cin >> amount;
                accounts[index].deposit(amount);
                cout << "New balance: $" << fixed << setprecision(2) << accounts[index].getBalance() << endl;
            } else {
                cout << "\n[Account NOT found!]" << endl;
            }
        }
        else if (menuChoice == 7) {
            // Withdraw money
            string searchName;
            cout << "\nEnter account name for withdrawal: ";
            cin.ignore();
            getline(cin, searchName);
            
            int index = searchAccountByName(accounts, accountCount, searchName);
            if (index != -1) {
                double amount;
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                accounts[index].withdraw(amount);
                cout << "New balance: $" << fixed << setprecision(2) << accounts[index].getBalance() << endl;
            } else {
                cout << "\n[Account NOT found!]" << endl;
            }
        }
        else if (menuChoice == 8) {
            cout << "\nExiting system..." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (true);

    cout << "\n========================================" << endl;
    cout << "  DESTRUCTORS WILL BE CALLED BELOW" << endl;
    cout << "========================================\n" << endl;

    return 0;
}
