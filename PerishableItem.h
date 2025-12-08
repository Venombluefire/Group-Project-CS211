#ifndef PERISHABLEITEM_H
#define PERISHABLEITEM_H

#include "PantryItem.h"
#include <iostream>
using namespace std;   // Added

class PerishableItem : public PantryItem {
    string expiry;

public:
    PerishableItem(int id, const string& name, int qty, const string& exp)
        : PantryItem(id, name, qty), expiry(exp) {}

    string serialize() const override {
        return "P," + to_string(id) + "," + name + "," +
               to_string(quantity) + "," + expiry;
    }

    void display() const override {
        cout << "[Perishable] " << name << " | Qty: " << quantity
             << " | Exp: " << expiry << "\n";
    }
};

#endif

