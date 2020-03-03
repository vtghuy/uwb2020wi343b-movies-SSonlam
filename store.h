#ifndef STORE_H
#define STORE_H

#include "bstree.h"
#include "customer.h"
#include "movie.h"
#include "moviefactory.hpp"
#include "hashtable.h"

#include <fstream>
#include <map>
#include <vector>

using namespace std;


class Store
{
public:
    Store();
    ~Store();
    bool CreateCustomers(const string &FileName);
    bool ReadMoviesFromFile(const string &FileName);
    bool readCommands(const string &FileName);

private:
    HashTable CustomerTable;
    MovieFactory Factory;
    map<char, BSTree> MovieMap;
};
#endif

