#ifndef RETURN_H
#define RETURN_H

class Return : public Command
{
public:
    Command *Create() override { return new Return(); }
    bool read(istream &is) {
        is >> ClientID;
    }
};
#endif