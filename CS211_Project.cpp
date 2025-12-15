#include "PantryDB.h"
#include <iostream>
using namespace std;

int main() {
    // Create a PantryDB object, loading data from pantry.txt at startup
    PantryDB db("pantry.txt");
    int choice;

    // Main loop: keep showing menu until user chooses Exit
    while (true) {
        cout << "\n1. Add Item\n2. List Items\n3. Search Item\n4. Delete Item\n5. Update Quantity\n6. Exit\nChoice: ";
        cin >> choice;
        cin.ignore(); // clear newline left in input buffer

        if (choice == 1) {
            // Add Item
            string name, expiry;
            int qty;

            cout << "Enter Name: ";
            getline(cin, name); // read full line for item name
            cout << "Enter Quantity: ";
            cin >> qty;
            cin.ignore(); // clear newline
            cout << "Enter Expiry (MM-DD-YYYY): ";
            getline(cin, expiry);

            // Construct PantryItem using constructor (no direct member access)
            PantryItem item(name, qty, expiry);
            db.addItem(item); // add to database and save to file
        }
        else if (choice == 2) {
            // List Items
            db.listItems(); // display all items in pantry
        }
        else if (choice == 3) {
            // Search Item
            string searchName;
            cout << "Enter name to search: ";
            getline(cin, searchName);
            db.searchItem(searchName); // look up item by name
        }
        else if (choice == 4) {
            // Delete Item
            string deleteName;
            cout << "Enter name to delete: ";
            getline(cin, deleteName);
            db.deleteItem(deleteName); // remove item if found
        }
        else if (choice == 5) {
            // Update Quantity
            string updateName;
            int newQty;
            cout << "Enter name to update: ";
            getline(cin, updateName);
            cout << "Enter new quantity: ";
            cin >> newQty;
            cin.ignore();
            db.updateQuantity(updateName, newQty); // set new quantity
        }
        else if (choice == 6) {
            // Exit
            cout << "Exiting pantry system...\n";
            break; // end loop and program
        }
        else {
            // Invalid choice
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
