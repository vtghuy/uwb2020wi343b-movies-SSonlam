#ifndef CLASSIC_H
#define CLASSIC_H

//#include "movie.h"

class Classic : public Movie
{
public:
    Movie *Create() override { return new Classic(); }

    int getReleaseMonth() {
        return ReleaseMonth;
    }

    string getActorFirst() {
        return MajorActorFirst;
    }

    bool read(istream &is) {
        char DiscardComma;
        is >> DiscardComma;
        is >> Stock;
        is >> DiscardComma;
        Director = readNextItem(is);
        Title = readNextItem(is);
        is >> MajorActorFirst >> MajorActorLast >> ReleaseMonth >> ReleaseYear;
        return true;
    }

    bool operator < (Movie &comparedMovie) {
        if (getReleaseYear() < comparedMovie.getReleaseYear()) {
            return true;
        }

        else if (getReleaseYear() == comparedMovie.getReleaseYear()) {
            //cout << "wtf" << endl;
            if (getReleaseMonth() < comparedMovie.getReleaseMonth()) {
                return true;
            }
            else if (getReleaseMonth() == comparedMovie.getReleaseYear()) {
                if (getActorFirst().compare(comparedMovie.getActorFirst()) < 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }

        else {
            return false;
        }
    }

    bool operator > (Movie* comparedMovie) {
        if (getReleaseYear() < comparedMovie->getReleaseYear()) {
            return false;
        }

        else if (getReleaseYear() == comparedMovie->getReleaseYear()) {
            if (getReleaseMonth() < comparedMovie->getReleaseMonth()) {
                return false;
            }
            else if (getReleaseMonth() == comparedMovie->getReleaseYear()) {
                if (getActorFirst().compare(comparedMovie->getActorFirst()) < 0) {
                    return false;
                }
            }
        }

        else {
            return true;
        }
    }


    ostream &printer(ostream& os) const override {
        os << "Classic: " << Stock << " " << Director << " " << Title << " " << MajorActorFirst << " " << MajorActorLast << " " << ReleaseMonth << " " << ReleaseYear;
        return os;
    }
private:
    string MajorActorFirst;
    string MajorActorLast;
    int ReleaseMonth;
};
#endif;