/**
 * Driver for starting movie store tests
 */
#include "moviefactory.hpp"
#include "store.h"

#include <iostream>
#include <fstream>
using namespace std;

// forward declaration, implementation in store_test.cpp
//void testAll();

int main() {
    Store MovieStore;
    MovieStore.CreateCustomers("data4customers.txt");
    MovieStore.ReadMoviesFromFile("data4movies.txt");
    MovieStore.readCommands("data4commands.txt");
    //testAll();
    cout << "Done." << endl;
    return 0;
}
