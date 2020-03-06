#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"

#include <string>
#include <vector>

using namespace std;

class Customer
{
public:
    friend ostream& operator<<(ostream& os, const Customer& customer);
    Customer();
    Customer(int ID, string LName, string FName);
    ~Customer();
    void addToHistory(char CommandType, Movie* tempMovie);
    int GetID();
    vector<string> History;
private:
    int CustomerID;
    string LastName;
    string FirstName;
  //  vector<string> History;
};
#endif
