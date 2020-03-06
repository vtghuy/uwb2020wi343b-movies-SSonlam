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
    Inventory['F'] = new BSTree();
    Inventory['D'] = new BSTree();
    Inventory['C'] = new BSTree();
    while (InFile >> MovieType) {
        Movie *TempMovie = Factory.create(MovieType);
        if (TempMovie) {
            if (TempMovie->read(InFile)) {
                Inventory[MovieType]->insert(TempMovie);
            }
        }
        else {
            TempMovie->discardLine(InFile);
            cout << "Now discarding line" << endl;
        }
    }
    return true;
}

bool Store::readCommands(const string &FileName) {
    ifstream InFile;
    InFile.open(FileName);
    if (!InFile) {
        cout << "Failure opening file";
    }
    char CommandType;
    while (InFile >> CommandType) {
        Command *TempCommand = CFactory.create(CommandType);
        if (TempCommand) {
            if (TempCommand->read(InFile)) {
                Customer* TempCustomer = nullptr;
                    switch (CommandType) {
                    case 'B':
                        TempCustomer = CustomerTable.retrieve(TempCommand->getClientID());
                        if (TempCustomer != nullptr) {
                            TempCommand->executeBorrow(CommandType, TempCustomer, Inventory[TempCommand->getMovieType()]);
                        }
                        break;
                    case 'R':
                        TempCustomer = CustomerTable.retrieve(TempCommand->getClientID());
                        if (TempCustomer != nullptr) {
                            TempCommand->executeReturn(CommandType, TempCustomer, Inventory[TempCommand->getMovieType()]);
                        }
                        break;
                    case 'H':
                        TempCustomer = CustomerTable.retrieve(TempCommand->getClientID());
                        if (TempCustomer != nullptr) {
                            TempCommand->executeHistory(TempCustomer);
                        }
                        break;
                    case 'I':
                        TempCommand->executeInventory(Inventory);
                        break;
                    default:
                        cout << "Unrecognized command, will not perform: " << CommandType << endl;
                        break;

                    }               
            }
        }
        else {
            TempCommand->discardLine(InFile);
        }
    }
    return true;
}