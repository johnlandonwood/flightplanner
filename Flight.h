#ifndef INC_20F_FLT_PLN_Flight_H
#define INC_20F_FLT_PLN_Flight_H
#include "DSString.h"

class Flight {
private:
    DSString FlightPath;
    float cost;
    int time;
    DSString airline;
public:
    Flight();
    Flight(DSString headCity);
    Flight(DSString FlightPath, float cost, int time, DSString airline);
    bool operator== (const Flight& rhs) const;
    void printFlight();
    DSString getFlightPath() const;
    float getCost() const;
    int getTime() const;
    DSString getAirline() const;
    void setFlightPath(DSString newFlightPath);
    void setCost(float newCost);
    void setTime(int newTime);
    void setAirline(DSString newAirline);

};

#endif //INC_20F_FLT_PLN_Flight_H
