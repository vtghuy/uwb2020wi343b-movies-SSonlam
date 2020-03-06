#include "customer.h"

using namespace std;


Customer::Customer()
{
}

Customer::Customer(int ID, string LName, string FName) {
   CustomerID = ID;
   LastName = LName;
   FirstName = FName;
}


Customer::~Customer()
{
}

ostream& operator<<(ostream& os, const Customer& customer) {
    os << customer.CustomerID << " " << customer.LastName << " " << customer.FirstName;
    return os;
}

int Customer::GetID() {
    return CustomerID;
}

void Customer::addToHistory(char CommandType, Movie* tempMovie) {
    string line;
    switch (CommandType) {
    case 'B':
        line = "Borrowed: " + tempMovie->getTitle() + " " + tempMovie->getDirector() + " " + tempMovie->getActorFirst() + " " + tempMovie->getActorLast();
        break;
    case 'R':
        line = "Returned: " + tempMovie->getTitle() + " " + tempMovie->getDirector() + " " + tempMovie->getActorFirst() + " " + tempMovie->getActorLast();
    default:
        break;
    }
    History.push_back(line);
}
