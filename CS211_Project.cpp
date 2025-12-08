#include <iostream>
#include "PantryDB.h"

using namespace std;

int main() {
    PantryDB db("pantry.txt");

    try {
        db.addItem(new PerishableItem(1, "Milk", 10, "2025-12-20"));
        db.addItem(new NonPerishableItem(2, "Rice", 50));

        db.saveToFile();
        cout << "Data saved successfully." << endl;

        PantryDB db2("pantry.txt");
        db2.loadFromFile();
        db2.displayAll();
    }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    return 0;
}
