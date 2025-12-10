#include "PantryDB.h"
#include <iostream>
using namespace std;

int main() {
    PantryDB db("pantry.txt");
    int choice;

    while (true) {
        cout << "\n1. Add Item\n2. List Items\n3. Search Item\n4. Delete Item\n5. Update Quantity\n6. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            PantryItem item;
            cout << "Enter Name: ";
            getline(cin, item.name);
            cout << "Enter Quantity: ";
            cin >> item.quantity;
            cin.ignore();
            cout << "Enter Expiry (YYYY-MM-DD): ";
            getline(cin, item.expiry);
            db.addItem(item);
        }
        else if (choice == 2) {
            db.listItems();
        }
        else if (choice == 3) {
            string searchName;
            cout << "Enter name to search: ";
            getline(cin, searchName);
            db.searchItem(searchName);
        }
        else if (choice == 4) {
            string deleteName;
            cout << "Enter name to delete: ";
            getline(cin, deleteName);
            db.deleteItem(deleteName);
        }
        else if (choice == 5) {
            string updateName;
            int newQty;
            cout << "Enter name to update: ";
            getline(cin, updateName);
            cout << "Enter new quantity: ";
            cin >> newQty;
            cin.ignore();
            db.updateQuantity(updateName, newQty);
        }
        else break;
    }
}
