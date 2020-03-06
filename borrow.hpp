#ifndef BORROW_H
#define BORROW_H

class Borrow : public Command
{
public:
    Command *Create() override { return new Borrow(); }

    bool read(istream &is) {
        is >> ClientID;
        is >> MediaType;
        is >> MovieType;
        switch (MovieType) {
        case 'C': {
            is >> ReleaseMonth;
            is >> ReleaseYear;
            is >> MajorActorFirst;
            is >> MajorActorLast;
            break;
        }
        case 'D': {
            Director = readNextItem(is);
            Title = readNextItem(is);
            break;
        }
        case 'F': {
            Title = readNextItem(is);
            is >> ReleaseYear;
            break;
        }
        default: {
            cout << "invalid movie type: " << MovieType << endl;
            discardLine(is);
            return false;
        }
        }
        return true;
    }
    bool executeBorrow(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) {
        Movie* tempMovie = nullptr;
        
        switch (MovieType) {   
        case 'F':
            inputTree->retrieve(getTitle(), tempMovie);
            break;
        case 'C':
            inputTree->retrieveInt(getReleaseYear(), getReleaseMonth(), getActorFirst(), getActorLast(), tempMovie);
            break;
        case 'D':
            inputTree->retrieveDrama(getDirector(), getTitle(), tempMovie);
            break;
        default:
            cout << "No such movie in inventory to perform a borrow on" << endl;
        }

        
        if (tempMovie != nullptr) {
            bool stockCheck = tempMovie->stockBorrowed();
            if (stockCheck) {
                inputCustomer->addToHistory(CommandType, tempMovie);
            }
            else {
                cout << "Unable to borrow movie, none in stock: " << *tempMovie << endl;
            }
        }      
        return false;
    }

    bool executeReturn(char CommandType, Customer *&inputCustomer, BSTree *&inputTree) {
        return false;
    }

    bool executeInventory(map<char, BSTree*> tempMap) {
        return true;
    }
    bool executeHistory(Customer *&inputCustomer) {
        return true;
    }
};
#endif;