#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"

#include <iostream>
#include <iterator>
#include <list>

using namespace std;

const int TABLESIZE = 13;

class HashTable
{
public:
    HashTable();
    ~HashTable();
    void add(Customer *AddingCustomer);
    Customer* retrieve(int ID);
    bool doesCustomerExist(int ID);
private:
    list<Customer*> Table[TABLESIZE];
};
#endif

