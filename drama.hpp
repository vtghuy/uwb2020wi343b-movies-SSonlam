#ifndef DRAMA_H
#define DRAMA_H

//#include "movie.h"

class Drama : public Movie
{
public:
    Movie *Create() override { return new Drama(); }

    bool operator < (Movie &comparedMovie) {

        if (getDirector().compare(comparedMovie.getDirector()) < 0) {
            return true;
        }
        else if (getDirector().compare(comparedMovie.getDirector()) == 0) {
            if (getTitle().compare(comparedMovie.getTitle()) < 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    bool operator > (Movie* comparedMovie) {
        if (getReleaseYear() < comparedMovie->getReleaseYear()) {
            return true;
        }

        else if (getReleaseYear() == comparedMovie->getReleaseYear()) {
            if (getReleaseMonth() < comparedMovie->getReleaseMonth()) {
                return true;
            }
            else if (getReleaseMonth() == comparedMovie->getReleaseYear()) {
                if (getActorFirst().compare(comparedMovie->getActorFirst()) < 0) {
                    return true;
                }
            }
        }

        else {
            return false;
        }
    }


    bool read(istream &is) {
        char DiscardComma;
        is >> DiscardComma;
        is >> Stock;
        is >> DiscardComma;
        Director = readNextItem(is);
        Title = readNextItem(is);
        is >> ReleaseYear;
        return true;
    }


    ostream &printer(ostream& os) const override {
        os << "Drama: " << Stock << " " << Director << " " << Title << " " << ReleaseYear;
        return os;
    }

};
#endif;
