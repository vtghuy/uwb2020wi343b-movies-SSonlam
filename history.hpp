#ifndef HISTORY_H
#define HISTORY_H

class History : public Command
{
public:
    Command *Create() override { return new History(); }
    bool read(istream &is) {
        is >> ClientID;
        return true;
    }
    bool executeHistory(Customer *&inputCustomer) {
        if (inputCustomer) {
            cout << "Customer history for: " << *inputCustomer << endl;
            for (int i = 0; i < inputCustomer->History.size(); i++) {
                cout << inputCustomer->History[i] << endl;

            }
            cout << endl;
        }
        return true;
    }
    bool executeInventory(map<char, BSTree*> tempMap) {
        return true;
    }
    bool executeBorrow(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) {
        return true;
    }
    bool executeReturn(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) {
        return false;
    }

};
#endif