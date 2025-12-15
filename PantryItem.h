#ifndef PANTRYITEM_H
#define PANTRYITEM_H

#include <string>
#include <iostream>
using namespace std;

// Represents a single pantry item with a name, quantity, and expiry date.
class PantryItem {
private:   // Data members are private to enforce encapsulation
    string name;      // Item name (e.g., "Beans")
    int quantity;     // How many units of the item
    string expiry;    // Expiry date in MM-DD-YYYY format

public:
    // Default constructor initializes an "empty" item
    PantryItem() : name(""), quantity(0), expiry("") {}

    // Constructor with parameters for quick creation
    PantryItem(string n, int q, string e) : name(n), quantity(q), expiry(e) {}

    // --- Getters ---
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    string getExpiry() const { return expiry; }

    // --- Setters ---
    void setName(const string& n) { name = n; }
    void setQuantity(int q) { quantity = q; }
    void setExpiry(const string& e) { expiry = e; }

    // Display item details in a readable format
    void display() const {
        cout << name << " (" << quantity << ") expires: " << expiry << "\n";
    }
};

#endif
