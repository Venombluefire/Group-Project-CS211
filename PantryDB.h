#ifndef PANTRYDB_H
#define PANTRYDB_H

#include "PantryItem.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class PantryDB {
    vector<PantryItem> items;
    string filename;

public:
    PantryDB(string fname) : filename(fname) { loadFromFile(); }

    void addItem(const PantryItem& item) {
        items.push_back(item);
        saveToFile();
    }

    void listItems() const {
        for (const auto& item : items) {
            cout << "Name: " << item.name
                << " | Qty: " << item.quantity
                << " | Exp: " << item.expiry << "\n";
        }
    }

    void searchItem(const string& searchName) const {
        for (const auto& item : items) {
            if (item.name == searchName) {
                cout << "Found -> " << item.name
                    << " | Qty: " << item.quantity
                    << " | Exp: " << item.expiry << "\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void deleteItem(const string& deleteName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == deleteName) {
                items.erase(it);
                saveToFile();
                cout << "Item deleted.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }
    void updateQuantity(const string& itemName, int newQty) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.quantity = newQty;
                saveToFile();
                cout << "Quantity updated for " << itemName << ".\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void saveToFile() {
        ofstream ofs(filename);
        for (const auto& item : items) {
            ofs << item.name << "," << item.quantity << "," << item.expiry << "\n";
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        string line;
        while (getline(ifs, line)) {
            if (line.empty()) continue;
            PantryItem item;
            size_t p1 = line.find(',');
            size_t p2 = line.find(',', p1 + 1);
            item.name = line.substr(0, p1);
            item.quantity = stoi(line.substr(p1 + 1, p2 - p1 - 1));
            item.expiry = line.substr(p2 + 1);
            items.push_back(item);
        }
    }
};

#endif
