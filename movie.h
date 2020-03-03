#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie
{
    friend ostream &operator<<(ostream &os, const Movie &m) { return m.printer(os); }
public:
    virtual Movie *Create() = 0;
    virtual bool read(istream &is) = 0;
    virtual ostream &printer(ostream& os) const = 0;
    virtual bool operator < (Movie &comparedMovie) = 0;
    virtual bool operator > (Movie* comparedMovie) = 0;
    string readNextItem(istream &io, char delimiter = ',');
    string readNextActor(istream &io, char delimiter = ' ');
    int getReleaseYear() { return ReleaseYear; }
    virtual int getReleaseMonth() { return 0; }
    virtual string getActorFirst() { return " "; }
    const string discardLine(istream &is);
    string getTitle();
    string getDirector();
    virtual ~Movie() = default;

protected:
    string Director;
    string Title;
    int ReleaseYear;
    int Stock;
    vector<string> History;
};
#endif;

