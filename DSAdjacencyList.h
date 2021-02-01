#ifndef INC_20F_FLT_PLN_DSADJACENCYLIST_H
#define INC_20F_FLT_PLN_DSADJACENCYLIST_H
#include "DSList.h"
#include "DSVector.h"
#include "DSString.h"
#include "Flight.h"
#include "DSStack.h"
// Adjacency List class, specifically tailored to the purposes of this project

class DSAdjacencyList {
private:
    DSVector<DSList<Flight>> cities;
public:
    DSAdjacencyList();
    void addFlight(Flight flight);
    DSList<Flight>& operator[](DSString headCityName);
    DSList<Flight>& operator[](int location);
    DSVector<DSList<Flight>>& getCities();
    void populateList(ifstream& input);
    void print();
    bool doesHeadCityExist(DSString headCityName);
    bool searchStack(DSStack<Flight> stack, Flight key);
    bool searchStackForHeadCity(DSStack<Flight> stack, Flight key);
    int getSourceIndex(DSString source);
};


#endif //INC_20F_FLT_PLN_DSADJACENCYLIST_H1
