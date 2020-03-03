#include "hashtable.h"



HashTable::HashTable()
{
}


HashTable::~HashTable()
{
}

//adding customer to hash table, does not take duplicate IDs
void HashTable::add(Customer *AddingCustomer) {
    if (doesCustomerExist(AddingCustomer->GetID())) { 
        cout << "Customer already exists, adding failed" << endl;
        return; 
    }
    //chaining logic
    int index = AddingCustomer->GetID() % TABLESIZE;
    Table[index].push_back(AddingCustomer);
}

//retrieves customer pointer to perform commands on
Customer* HashTable::retrieve(int ID) {
    if (!doesCustomerExist(ID)) { 
        cout << "Customer does not exist, retrieval failed" << endl;
        return nullptr; 
    }
    //list iterator 
    list<Customer*>::iterator Itr;
    int index = ID % TABLESIZE;
    for (Itr = Table[index].begin(); Itr != Table[index].end(); Itr++) {
        Customer* temp = *Itr;
        if (ID == temp->GetID()) {
            cout << *temp << endl;
            return temp;
        }
    }
    return nullptr;
}

//checks to see if customer exists inside hash table
bool HashTable::doesCustomerExist(int ID) {
    //list iterator 
    list<Customer*>::iterator Itr;
    int index = ID % TABLESIZE;
    for (Itr = Table[index].begin(); Itr != Table[index].end(); Itr++) {
        Customer* temp = *Itr;
        if (ID == temp->GetID()) {
            return true;
        }
    }
    return false;
}
