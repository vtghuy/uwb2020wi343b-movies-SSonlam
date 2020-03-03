#include "store.h"



Store::Store()
{
}

Store::~Store()
{
}

bool Store::CreateCustomers(const string &FileName) {
    //read in file with expected formatting
        ifstream InFile;
        InFile.open(FileName);
        if (!InFile) {
            cout << "Failure opening file";
        }

        int ID;
        string LastName;
        string FirstName;

        //expected we know file formatting already
        while (InFile >> ID >> LastName >> FirstName) {
            Customer *StoreCustomer = new Customer(ID, LastName, FirstName);
            CustomerTable.add(StoreCustomer);
        }

        InFile.close();
        return true;
    }


bool Store::ReadMoviesFromFile(const string &FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Failure opening file";
    }
    char MovieType;
    while (InFile >> MovieType) {
        Movie *TempMovie = Factory.create(MovieType);
        if (TempMovie) {
            if (TempMovie->read(InFile)) {
             //   cout << "this is " << *TempMovie << endl;
                MovieMap[MovieType].insert(TempMovie);
            }
        }
        else {
            TempMovie->discardLine(InFile);
            cout << "Now discarding line" << endl;
        }
    }
    MovieMap['F'].display();
    return true;
}

bool Store::readCommands(const string &FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Failure opening file";
    }
    string Line;
    while (InFile.good()) {
        getline(InFile, Line);
        
    }
    return true;
}