#ifndef INC_20F_FLT_PLN_FLIGHTPLANNER_H
#define INC_20F_FLT_PLN_FLIGHTPLANNER_H
#include <fstream>
#include "DSString.h"
#include "Request.h"
#include "DSVector.h"

class FlightPlanner {
public:
    FlightPlanner();
    void planFlights(char* argv1, char* argv2, char* argv3);
};


#endif //INC_20F_FLT_PLN_FLIGHTPLANNER_H
