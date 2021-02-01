#ifndef INC_20F_FLT_PLN_REQUEST_H
#define INC_20F_FLT_PLN_REQUEST_H
#include <fstream>
#include "DSString.h"

class Request {
private:
    DSString source;
    DSString destination;
    char sortCriteria;
public:
    Request();
    Request(DSString source, DSString destination, char sortCriteria);
    bool operator== (const Request& rhs) const;
    DSString getSource() const;
    DSString getDestination() const;
    char getSortCriteria() const;
    void setSource(DSString newSource);
    void setDestination(DSString newDestination);
    void setSortCriteria(char newCriteria);
    void printRequest();
};


#endif //INC_20F_FLT_PLN_REQUEST_H
