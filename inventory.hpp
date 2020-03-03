#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory : public Command
{
public:
    Command *Create() override { return new Inventory(); }
    bool read(istream &is) {
        return true;
    }
};
#endif