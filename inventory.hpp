#ifndef INVENTORY_H
#define INVENTORY_H

#include "bstree.h"

#include <iterator>

class Inventory : public Command
{
public:
    Command *Create() override { return new Inventory(); }
    bool read(istream &is) {
        return true;
    }
    bool executeInventory(map<char, BSTree*> tempMap) {
        cout << "Store Inventory:" << endl;
        tempMap['F']->display();
        tempMap['D']->display();
        tempMap['C']->display();
        cout << endl;
        return true;
    }
    bool executeHistory(Customer *&inputCustomer) {
        return true;
    }
    bool executeBorrow(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) {
        return false;
    }
    bool executeReturn(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) {
        return false;
    }

};
#endif