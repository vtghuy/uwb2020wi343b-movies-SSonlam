#ifndef COMEDY_H
#define COMEDY_H

//#include "movie.h"

class Comedy : public Movie
{
public:
    Movie *Create() override { return new Comedy(); }


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

    bool operator < (Movie &comparedMovie) {
        if (getTitle().compare(comparedMovie.getTitle()) < 0) {
            return true;
        }
        else if (getTitle().compare(comparedMovie.getTitle()) == 0) {
            if (getReleaseYear() < comparedMovie.getReleaseYear()) {
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

    ostream &printer(ostream& os) const override {
        os << "Comedy: " << Stock << " " << Director << " " << Title << " " << ReleaseYear;
        return os;
    }
private:

};
#endif;
