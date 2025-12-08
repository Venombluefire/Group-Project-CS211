#ifndef PANTRYDB_H
#define PANTRYDB_H

#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "PerishableItem.h"
#include "NonPerishableItem.h"
using namespace std;   // Added

class PantryDB {
    string filename;
    vector<PantryItem*> items;

public:
    PantryDB(const string& fname) : filename(fname) {}
    ~PantryDB() {
        for (auto i : items) delete i;
    }

    void addItem(PantryItem* item) {
        items.push_back(item);
    }

    void saveToFile() {
        ofstream ofs(filename);
        if (!ofs) throw runtime_error("Error: Cannot open file for writing.");
        for (auto i : items) {
            ofs << i->serialize() << "\n";
        }
    }

    void loadFromFile() {
        ifstream ifs(filename);
        if (!ifs) throw runtime_error("Error: Cannot open file for reading.");

        string line;
        while (getline(ifs, line)) {
            istringstream iss(line);
            string type;
            getline(iss, type, ',');

            if (type == "P") {
                int id, qty; string name, exp, token;
                getline(iss, token, ','); id = stoi(token);
                getline(iss, name, ',');
                getline(iss, token, ','); qty = stoi(token);
                getline(iss, exp, ',');
                items.push_back(new PerishableItem(id, name, qty, exp));
            } else if (type == "N") {
                int id, qty; string name, token;
                getline(iss, token, ','); id = stoi(token);
                getline(iss, name, ',');
                getline(iss, token, ','); qty = stoi(token);
                items.push_back(new NonPerishableItem(id, name, qty));
            } else {
                throw runtime_error("Error: Unknown item type in file.");
            }
        }
    }

    void displayAll() const {
        for (auto i : items) {
            i->display();  // polymorphic call
        }
    }
};

#endif

