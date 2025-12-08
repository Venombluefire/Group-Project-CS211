#ifndef PANTRYITEM_H
#define PANTRYITEM_H

#include <string>
using namespace std;   // Added

class PantryItem {
protected:
    int id;
    string name;
    int quantity;

public:
    PantryItem(int id, const string& name, int qty)
        : id(id), name(name), quantity(qty) {}
    virtual ~PantryItem() = default;

    virtual string serialize() const = 0;   // pure virtual
    virtual void display() const = 0;       // polymorphic display

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
};

#endif

