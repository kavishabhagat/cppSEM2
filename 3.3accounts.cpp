/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 12 March 2025
   3.3 MANAGING BANCK Accounts */

#include <iostream>
using namespace std;

class Accounts
{
    int accno;
    string name;
    int balance;

public:
    Accounts(int a, string n, int b)
    {
        accno = a;
        name = n;
        balance = b;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accno
                 << ". New balance: " << balance << "\n";
        }
        else
        {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accno
                 << ". New balance: " << balance << "\n";
        }
        else
        {
            cout << "Insufficient funds.\n";
        }
    }

    void transfer(Accounts* target, int amount)
    {
        if (!target)
        {
            cout << "Target account does not exist.\n";
            return;
        }

        if (amount <= 0)
        {
            cout << "Invalid transfer amount.\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Transfer failed: Insufficient funds.\n";
            return;
        }

        withdraw(amount);
        target->deposit(amount);
        cout << "Transferred " << amount << " from account " << accno
             << " to account " << target->accno << "\n";
    }

    void display() const
    {
        cout << "ACCOUNT NUMBER: " << accno << endl << "NAME: " << name
             <<endl<< "BALANCE: " << balance << "\n";
    }

    int getAccountNumber() const
    {
        return accno;
    }
};


Accounts* findaccount(Accounts** a, int totalAccounts, int accno)
{
    for (int i = 0; i < totalAccounts; ++i)
    {
        if (a[i]->getAccountNumber() == accno)
        {
            return a[i];
        }
    }
    return nullptr;
}

int main()
{
    Accounts* a[100];
    int totalAccounts = 0;
    int choice;

    // Menu-driven system to input Accounts and operations
    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Display Account Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Create new account
            int accno;
            string name;
            int balance;
            cout << "Enter Account Number: ";
            cin >> accno;
            cin.ignore(); // To clear the newline character
            cout << "Enter Account Holder's Name: ";
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> balance;

            a[totalAccounts++] = new Accounts(accno, name, balance);
            cout << "Account created successfully!\n";
            break;
        }
        case 2:
        {
            // Deposit
            int accno, amount;
            cout << "Enter Account Number to Deposit: ";
            cin >> accno;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            Accounts* acc = findaccount(a, totalAccounts, accno);
            if (acc)
            {
                acc->deposit(amount);
            }
            else
            {
                cout << "Account not found!\n";
            }
            break;
        }
        case 3:
        {
            // Withdraw
            int accno, amount;
            cout << "Enter Account Number to Withdraw from: ";
            cin >> accno;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            Accounts* acc = findaccount(a, totalAccounts, accno);
            if (acc)
            {
                acc->withdraw(amount);
            }
            else
            {
                cout << "Account not found!\n";
            }
            break;
        }
        case 4:
        {
            // Transfer
            int sourceAccno, targetAccno, amount;
            cout << "Enter Source Account Number: ";
            cin >> sourceAccno;
            cout << "Enter Target Account Number: ";
            cin >> targetAccno;
            cout << "Enter Amount to Transfer: ";
            cin >> amount;

            Accounts* sourceAcc = findaccount(a, totalAccounts, sourceAccno);
            Accounts* targetAcc = findaccount(a, totalAccounts, targetAccno);

            if (sourceAcc && targetAcc)
            {
                sourceAcc->transfer(targetAcc, amount);
            }
            else
            {
                cout << "One or both Accounts not found!\n";
            }
            break;
        }
        case 5:
        {
            // Display Account Info
            int x;
            cout << "Enter Account Number to Display Info: ";
            cin >> x;

            Accounts* acc = findaccount(a, totalAccounts, x);
            if (acc)
            {
                cout<<"DISPLAYING DETAILS FOR ACCOUNT NUMBER "<< x <<":"<<endl;
                acc->display();
            }
            else
            {
                cout << "Account not found!\n";
            }
            break;
        }
        case 6:
            // Exit
            cout << "Exiting...THANKYOU\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    }
    while (choice != 6);


    for (int i = 0; i < totalAccounts; ++i)
    {
        delete a[i];
    }

    cout<<endl<<"Kavisha Bhagat 24CE07";
}
