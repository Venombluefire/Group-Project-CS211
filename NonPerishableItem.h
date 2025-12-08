#ifndef NONPERISHABLEITEM_H
#define NONPERISHABLEITEM_H

#include "PantryItem.h"
#include <iostream>
using namespace std;

class NonPerishableItem : public PantryItem {
public:
    NonPerishableItem(int id, const string& name, int qty)
        : PantryItem(id, name, qty) {}

    string serialize() const override {
        return "N," + to_string(id) + "," + name + "," + to_string(quantity);
    }

    void display() const override {
        cout << "[Non-Perishable] " << name << " | Qty: " << quantity << "\n";
    }
};

#endif

