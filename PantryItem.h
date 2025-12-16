#ifndef PANTRYITEM_H
#define PANTRYITEM_H

#include <string>
#include <iostream>
#include <stdexcept>
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

    // --- Setters with exceptions ---
    void setName(const string& n) {
        if (n.empty())
            throw invalid_argument("Item name cannot be empty.");
        name = n;
    }
    void setQuantity(int q) {
        if (q < 0)
            throw invalid_argument("Quantity cannot be negative.");
        quantity = q;
    }
    void setExpiry(const string& e) {
        if (e.empty())
            throw invalid_argument("Expiry date cannot be empty.");
        expiry = e;
    }

    // Display item details in a readable format
    void display() const {
        cout << name << " (" << quantity << ") expires: " << expiry << "\n";
    }
};

#endif