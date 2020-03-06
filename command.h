#ifndef COMMAND_H
#define COMMAND_H

#include "bstree.h"
#include "customer.h"
#include "movie.h"

#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Command
{
    //friend ostream &operator<<(ostream &os, const Movie &m) { return m.printer(os); }
public:
    virtual Command *Create() = 0;
    virtual bool read(istream &is) = 0;
    virtual bool executeInventory(map<char, BSTree*> tempMap) = 0;
    virtual bool executeHistory(Customer *&inputCustomer) = 0;
    virtual bool executeBorrow(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) = 0;
    virtual bool executeReturn(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) = 0;
    string getTitle();
   // virtual ostream &printer(ostream& os) const = 0;
    int getClientID();
    int getReleaseYear();
    int getReleaseMonth();
    string getActorFirst();
    string getActorLast();
    string getDirector();
    char getMovieType();
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
};
#endif
