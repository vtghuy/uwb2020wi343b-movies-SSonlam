#include "command.h"
string Command::readNextItem(istream &io, char delimiter) {
    const char space = ' ';
    string str;
    getline(io, str, delimiter);
    if (str.empty())
        return str;
    else
        return str.substr(str.find_first_not_of(space),
            str.find_last_not_of(space) + 1);
}

const string Command::discardLine(istream &is) {
    string discard;
    getline(is, discard);
    return discard;
}

int Command::getClientID() {
    return ClientID;
}

string Command::getTitle() {
    return Title;
}

char Command::getMovieType() {
    return MovieType;
}

int Command::getReleaseYear() {
    return ReleaseYear;
}
int Command::getReleaseMonth() {
    return ReleaseMonth;
}

string Command::getActorFirst() {
    return MajorActorFirst;
}
string Command::getActorLast() {
    return MajorActorLast;
}
string Command::getDirector() {
    return Director;
}