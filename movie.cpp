#include "movie.h"



string Movie::readNextItem(istream &io, char delimiter) {
    const char space = ' ';
    string str;
    getline(io, str, delimiter);
    if (str.empty())
        return str;
    else
        return str.substr(str.find_first_not_of(space),
            str.find_last_not_of(space) + 1);
}

string Movie::readNextActor(istream &io, char delimiter) {
    const char space = ' ';
    string str;
    getline(io, str, delimiter);
    if (str.empty())
        return str;
    else
        return str.substr(str.find_first_not_of(space),
            str.find_last_not_of(space) + 1);
}

const string Movie::discardLine(istream &is) {
    string discard;
    getline(is, discard);
    return discard;
}

string Movie::getTitle() {
    return Title;
}

string Movie::getDirector() {
    return Director;
}

bool Movie::stockBorrowed() {
    if (0 < Stock) {
        --Stock;
        return true;
    }
    else {
        return false;
    }
}

void Movie::stockReturned() {
        ++Stock;
}

string Movie::getActorFirst() {
    return MajorActorFirst;
}
string Movie::getActorLast() {
    return MajorActorLast;
}