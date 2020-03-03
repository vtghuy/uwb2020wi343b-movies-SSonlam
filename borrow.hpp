#ifndef BORROW_H
#define BORROW_H

class Borrow : public Command
{
public:
    Command *Create() override { return new Borrow(); }

    bool read(istream &is) {
        is >> ClientID;
    }
};
#endif;