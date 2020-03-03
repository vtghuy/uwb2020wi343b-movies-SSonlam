#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer
{
public:
    friend ostream& operator<<(ostream& os, const Customer& customer);
    Customer();
    Customer(int ID, string LName, string FName);
    ~Customer();
    int GetID();
private:
    int CustomerID;
    string LastName;
    string FirstName;
};
#endif
