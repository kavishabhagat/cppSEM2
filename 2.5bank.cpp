/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 2 March 2025
   2.5 Loan MANAGEMENT SYSTEM */

#include <iostream>
#include <cmath>

using namespace std;

class Loan {
    int loanID;
    string name;
    double amount, rate;
    int term; // in months


    double calculateEMI() {
        double monthlyRate = rate / 12 / 100;
        return (amount * monthlyRate * pow(1 + monthlyRate, term)) /
               (pow(1 + monthlyRate, term) - 1);
    }

public:
    // Default Constructor
    Loan() {
        loanID = 0;
        name = "N/A";
        amount = 0.0;
        rate = 0.0;
        term = 0;
    }

    // Parameterized Constructor
    Loan(int id, string n, double a, double r, int t) {
        loanID = id;
        name = n;
        amount = a;
        rate = r;
        term = t;
    }

    void inputDetails() {
        cout << "\nEnter Loan ID: ";
        cin >> loanID;
        cin.ignore();
        cout << "Enter Applicant Name: ";
        getline(cin, name);
        cout << "Enter Loan Amount: ";
        cin >> amount;
        cout << "Enter Annual Interest Rate (in %): ";
        cin >> rate;
        cout << "Enter Loan Term (in months): ";
        cin >> term;
    }

    void displayDetails() {
        cout << "\n----------------------------\n";
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << name << endl;
        cout << "Loan Amount: " << amount << endl;
        cout << "Interest Rate: " << rate << "%" << endl;
        cout << "Loan Term: " << term << " months" << endl;
        cout << "EMI: " << calculateEMI() << " per month" << endl;
        cout << "----------------------------\n";
    }
};

int main() {
    int n;


    cout << "Enter the number of Loan applications: ";
    cin >> n;
    Loan loans[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for Loan " << i + 1 << ":";
        Loans[i].inputDetails();
    }

    cout << "\nALL Loan DETAILS:\n";
    for (int i = 0; i < n; i++) {
        Loans[i].displayDetails();
    }

    cout<<endl<<"Kavisha Bhagat-24CE007";
    return 0;
}
