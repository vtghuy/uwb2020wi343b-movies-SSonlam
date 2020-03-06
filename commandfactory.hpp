#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"
#include "borrow.hpp"
#include "return.hpp"
#include "inventory.hpp"
#include "history.hpp"

#include <iostream>

//using namespace std;

class CommandFactory
{
public:
    CommandFactory() {}
    //  ~MovieFactory() { for (const auto &m : Movies) delete m; };

    Command *create(char commandType) {
        // Movie *Movies;
        switch (commandType) {
        case 'B': {
            Commands = new Borrow();
            break;
        }
        case 'R': {
            Commands = new Return();
            break;
        }
        case 'H': {
            Commands = new History();
            break;
        }
        case 'I': {
            Commands = new Inventory();
            break;
        }
        default: {
            cout << "invalid command type: " << commandType << endl;
            return nullptr;
        }

                 Commands->Create();
        }
    }

private:
    Command *Commands;
};
#endif
