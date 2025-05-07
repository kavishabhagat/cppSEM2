/* THIS PROGRAM IS PREPARED BY 24CE007_KAVISHA
   Date of Modification- 1 May 2025
   7.3 FILE- INVENTORY*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product to the file
void addProduct() {
    Product p;
    cout << "Enter product name: ";
    cin.ignore();
    cin.getline(p.name, 50);

    cout << "Enter quantity: ";
    cin >> p.quantity;

    cout << "Enter price: ";
    cin >> p.price;

    ofstream file("inventory.txt", ios::app | ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file for writing.\n";
        return;
    }

    file.write(reinterpret_cast<char*>(&p), sizeof(Product));
    file.close();

    cout << "Product added successfully.\n";
}

// Function to display all products
void viewInventory() {
    ifstream file("inventory.txt", ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file.\n";
        return;
    }

    Product p;
    cout << "\n--- Inventory ---\n";
    while (file.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        cout << "Name    : " << p.name << endl;
        cout << "Quantity: " << p.quantity << endl;
        cout << "Price   : $" << p.price << "\n\n";
    }

    file.close();
}

// Function to search for a product by name
void searchProduct() {
    char searchName[50];
    cout << "Enter product name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);

    ifstream file("inventory.txt", ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file.\n";
        return;
    }

    Product p;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        if (strcmp(p.name, searchName) == 0) {
            cout << "\nProduct Found:\n";
            cout << "Name    : " << p.name << endl;
            cout << "Quantity: " << p.quantity << endl;
            cout << "Price   : $" << p.price << endl;
            found = true;
            break; // Stop after finding the first match
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }

    file.close();
}

// Main menu loop
int main() {
    int choice;
    do {
        cout << "=== Inventory Management ===\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    cout << endl << "Kavisha Bhagat 24CE007" << endl;
}

