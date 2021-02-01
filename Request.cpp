#include "Request.h"

Request::Request() {
    this->source = "";
    this->destination = "";
    this->sortCriteria = ' ';
}
Request::Request(DSString source, DSString destination, char sortCriteria) {
    this->source = source;
    this->destination = destination;
    this->sortCriteria = sortCriteria;
}
bool Request::operator==(const Request& rhs) const {
    if (this->source == rhs.source && this->destination == rhs.destination && this->sortCriteria == rhs.sortCriteria) {
        return true;
    }
    else return false;
}
DSString Request::getSource() const {
    return this->source;
}
DSString Request::getDestination() const {
    return this->destination;
}
char Request::getSortCriteria() const {
    return this->sortCriteria;
}
void Request::setSource(DSString newSource) {
    this->source = newSource;
}
void Request::setDestination(DSString newDestination) {
    this->destination = newDestination;
}
void Request::setSortCriteria(char newCriteria) {
    this->sortCriteria = newCriteria;
}
void Request::printRequest() {
    std::cout << "----Request----" << std::endl;
    std::cout << this->source << std::endl;
    std::cout << this->destination << std::endl;
    std::cout << this->sortCriteria << std::endl;
}