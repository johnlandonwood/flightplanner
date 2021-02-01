#ifndef INC_20F_FLT_PLN_PATH_H
#define INC_20F_FLT_PLN_PATH_H
#include "DSVector.h"
#include "DSString.h"
#include "Flight.h"
// A path object holds flight objects, designating the flights that have to be taken to complete the Request

class Path {
private:
    DSVector<Flight> flights;
    int totalTime;
    float totalCost;
public:
    Path();
    void addFlightToPath(Flight flight);
    void printPath(ofstream& output);
    void print();
    DSVector<Flight>& getFlights();
    int getTotalTime();
    float getTotalCost();
    void finalizePath();

};


#endif //INC_20F_FLT_PLN_PATH_H
