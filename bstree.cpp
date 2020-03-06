#include "bstree.h"

//constructors
BSTree::BSTree()
{
}

BSTree::~BSTree()
{
    makeEmpty();
}

//----------------------------------------------------------------------------
//function to insert a Client* into the binary tree, sets first value
//as the root then sorts future data going to the left subtree is value
//is smaller, and to the right if value is higher
bool BSTree::insert(Movie*& input) {
    Node* ptr = new Node;
    if (ptr == nullptr) return false;            // out of memory
    ptr->data = input;
    ptr->left = ptr->right = nullptr;
    if (isEmpty()) { //empty tree sets root to first client pointer
        root = ptr;
    }
    else {
        Node* current = root; // walking pointer
        bool inserted = false;                 // whether inserted yet
        // if item is less than current item, insert in left subtree,
        // otherwise insert in right subtree
        while (!inserted) {
            if (*ptr->data < *current->data) {
                if (current->left == nullptr) {              // insert left
                    current->left = ptr;
                    inserted = true;
                }
                else
                    current = current->left;               // one step left
            }
            else {
                if (current->right == nullptr) {             // insert right
                    current->right = ptr;
                    inserted = true;
                }
                else
                    current = current->right;              // one step right
            }
        }
    }
    return true;
}

//----------------------------------------------------------------------------
//check root to see if is nullptr
bool BSTree::isEmpty() const {
    if (root == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//----------------------------------------------------------------------------
//recursively prints all nodes of the binary tree
void BSTree::display()const {
    displayHelper(root);
}

//----------------------------------------------------------------------------
void BSTree::displayHelper(Node* ptr)const {
    //check for empty tree
    if (root == nullptr) {
        cout << "The tree is empty" << endl;
    }
    else {
        if (ptr->left != nullptr) {
            displayHelper(ptr->left);
        }

        cout << *ptr->data << endl;

        if (ptr->right != nullptr) {
            displayHelper(ptr->right);
        }
    }
}



//----------------------------------------------------------------------------
//function to retrieve reference of client pointer, stores to second param
bool BSTree::retrieve(const string inputName, Movie*& ptrHolder) const {
    //check to see empty tree
    if (root == nullptr) {
        cout << "Cannot perform retrieve, tree is empty" << endl;
        return false;
    }//calls client.getId to match ids
    //check to see if root is matching client
    else if (inputName == root->data->getTitle()) {
        ptrHolder = root->data;
        return true;
    }

    Node* current = root; // starts current at root
    //iterates through tree to try to find client
    while (current != nullptr) {
        if (inputName.compare(current->data->getTitle()) == 0) {
            ptrHolder = current->data;
            return true;
        }

        if (inputName.compare(current->data->getTitle()) < 0) {
            current = current->left;               // one step left
        }
        else {
            current = current->right;              // one step right
        }

    }
    //false if cannot find after iteration of tree
    return false;
}

bool BSTree::retrieveInt(const int inputYear, const int inputMonth, string ActorFirst, string ActorLast, Movie*& ptrHolder) const {
    //check to see empty tree
    if (root == nullptr) {
        cout << "Cannot perform retrieve, tree is empty" << endl;
        return false;
    }//calls client.getId to match ids
    //check to see if root is matching client
    else if (root->data->getActorFirst().compare(ActorFirst) == 0 && root->data->getActorLast().compare(ActorLast) == 0 &&
        root->data->getReleaseYear() == inputYear && root->data->getReleaseMonth() == inputMonth) {
        ptrHolder = root->data;
        return true;
    }
    Node* current = root; // starts current at root
    //iterates through tree to try to find client
    while (current != nullptr) {
        if (current->data->getActorFirst().compare(ActorFirst) == 0 && current->data->getActorLast().compare(ActorLast) == 0 &&
            current->data->getReleaseYear() == inputYear && current->data->getReleaseMonth() == inputMonth) {

            ptrHolder = current->data;
            return true;
        }

        if (inputYear < current->data->getReleaseYear()) {
            current = current->left;               // one step left
        }


        else if (inputYear == current->data->getReleaseYear()) {
            if (inputMonth < current->data->getReleaseMonth()) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }


        else {
            current = current->right;              // one step right
        }

    }
    //false if cannot find after iteration of tree
    ptrHolder = nullptr;
    return false;
}

//----------------------------------------------------------------------------
//function to retrieve reference of client pointer, stores to second param
bool BSTree::retrieveDrama(const string inputDirector, const string inputTitle, Movie*& ptrHolder) const {
    //check to see empty tree
    if (root == nullptr) {
        cout << "Cannot perform retrieve, tree is empty" << endl;
        return false;
    }//calls client.getId to match ids
    //check to see if root is matching client
    else if (inputDirector.compare(root->data->getDirector()) == 0 && inputTitle.compare(root->data->getTitle()) == 0) {
        ptrHolder = root->data;
        return true;
    }

    Node* current = root; // starts current at root
    //iterates through tree to try to find client
    while (current != nullptr) {
        if (inputDirector.compare(current->data->getDirector()) == 0 && inputTitle.compare(current->data->getTitle()) == 0) {
            ptrHolder = current->data;
            return true;
        }

        if (inputDirector.compare(current->data->getDirector()) < 0) {
            current = current->left;               // one step left
        }


        else if (inputDirector.compare(current->data->getDirector()) == 0) {
            if (inputTitle.compare(current->data->getTitle()) < 0) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }


        else {
            current = current->right;              // one step right
        }

    }
    //false if cannot find after iteration of tree
    return false;
}


//----------------------------------------------------------------------------
//uses recursion to delete every node of the tree
void BSTree::makeEmpty() {
    makeEmptyHelper(root);
    root = nullptr;

}

//----------------------------------------------------------------------------
void BSTree::makeEmptyHelper(Node* ptr) const {
    if (ptr == nullptr) return;

    // first delete both subtrees 
    makeEmptyHelper(ptr->left);
    makeEmptyHelper(ptr->right);

    // then delete the node 
    delete(ptr->data);
    delete(ptr);
}
