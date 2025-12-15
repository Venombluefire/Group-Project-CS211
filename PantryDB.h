#ifndef PANTRYDB_H
#define PANTRYDB_H

#include "PantryItem.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// PantryDB manages a collection of PantryItem objects.
// It supports adding, listing, searching, deleting, and updating items.
// Data is persisted to a file so the pantry survives across program runs.
class PantryDB {
private:
    vector<PantryItem> items;  // All pantry items stored in memory
    string filename;           // File used for saving/loading pantry data

public:
    // Constructor loads pantry data from file at startup
    PantryDB(string fname) : filename(fname) { loadFromFile(); }

    // Add a new item to the pantry and save to file
    void addItem(const PantryItem& item) {
        items.push_back(item);
        saveToFile();
    }

    // List all items currently in the pantry
    void listItems() const {
        for (const auto& item : items) {
            item.display();
        }
    }

    // Search for an item by name and display it if found
    void searchItem(const string& searchName) const {
        for (const auto& item : items) {
            if (item.getName() == searchName) {
                cout << "Found -> ";
                item.display();
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Delete an item by name and update the file
    void deleteItem(const string& deleteName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == deleteName) {
                items.erase(it);
                saveToFile();
                cout << "Item deleted.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Update the quantity of an existing item
    void updateQuantity(const string& itemName, int newQty) {
        for (auto& item : items) {
            if (item.getName() == itemName) {
                item.setQuantity(newQty);
                saveToFile();
                cout << "Quantity updated for " << itemName << ".\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

private:
    // Save all pantry items to file in CSV format
    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& item : items) {
            ofs << item.getName() << "," << item.getQuantity() << "," << item.getExpiry() << "\n";
        }
    }

    // Load pantry items from file at startup
    void loadFromFile() {
        ifstream ifs(filename);
        string line;
        while (getline(ifs, line)) {
            if (line.empty()) continue;
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);

            if (p1 == string::npos || p2 == string::npos) continue; // skip malformed lines

            string name = line.substr(0, p1);
            int qty = stoi(line.substr(p1 + 1, p2 - p1 - 1));
            string expiry = line.substr(p2 + 1);

            items.push_back(PantryItem(name, qty, expiry));
        }
    }
};

#endif
