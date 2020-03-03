#ifndef HISTORY_H
#define HISTORY_H

class History : public Command
{
public:
    Command *Create() override { return new History(); }
    bool read(istream &is) {
        is >> ClientID;
    }
};
#endif