#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "movie.h"
#include "classic.hpp"
#include "drama.hpp"
#include "comedy.hpp"

#include <iostream>

//using namespace std;

class MovieFactory
{
public:
    MovieFactory() {}
  //  ~MovieFactory() { for (const auto &m : Movies) delete m; };

    Movie *create(char MovieType) {
       // Movie *Movies;
        switch (MovieType) {
        case 'C': {
            Movies = new Classic();
            break;
        }
        case 'D': {
            Movies = new Drama();
            break;
        }
        case 'F': {
            Movies = new Comedy();
            break;
        }
        default: {
            cout << "invalid movie type: " << MovieType << endl;
            return nullptr;
        }

        Movies->Create();
        }
    }

private:
    Movie *Movies;
};
#endif
