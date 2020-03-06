#ifndef CLASSIC_H
#define CLASSIC_H

class Classic : public Movie
{
public:
    Movie *Create() override { return new Classic(); }

    int getReleaseMonth() {
        return ReleaseMonth;
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

    string getActorFirst() {
        return MajorActorFirst;
    }
    string getActorLast() {
        return MajorActorLast;
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