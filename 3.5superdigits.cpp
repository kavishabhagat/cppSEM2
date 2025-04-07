/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 12 March 2025
   3.5 FINDING SUPERDIGIT */
#include <iostream>
using namespace std;

long long superdigit(string n, int k) {
    long long sum = 0;
    for (char digit : n) {
        sum += digit - '0';
    }

    sum *= k;

    while (sum >= 10) {
        long long x = 0;
        while (sum > 0) {
            x += sum % 10;
            sum /= 10;
        }
        sum = x;
    }

    return sum;
}

int main() {
    string x;
    int k;
    cout << "Enter the Number as a String: ";
    cin >> x;
    cout << "Enter the Repetation Factor : ";
    cin >> k;

    cout << "Super Digit: " << superdigit(x, k);
    cout<<"Kavisha Bhagat 24CE007";
}
