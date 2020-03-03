#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Command
{
    //friend ostream &operator<<(ostream &os, const Movie &m) { return m.printer(os); }
public:
    virtual Command *Create() = 0;
    virtual bool read(istream &is) = 0;
    virtual bool transaction();
    virtual bool transaction(int x);
    /*
    virtual bool read(istream &is) = 0;
    virtual ostream &printer(ostream& os) const = 0;
    */
    string readNextItem(istream &io, char delimiter = ',');
    const string discardLine(istream &is);
    virtual ~Command() = default;

protected:
    int ClientID;
    char MediaType;
    char MovieType;
    string Director;
    string Title;
    int ReleaseYear;
    string MajorActorFirst;
    string MajorActorLast;
    int ReleaseMonth;

    /*
    string Director;
    string Title;
    int ReleaseYear;
    int Stock;
    vector<string> History;
    */
};
#endif
