#include "Flight.h"
using std::cout;
using std::endl;

Flight::Flight() {
    this->FlightPath = "";
    this->cost = 0.0;
    this->time = 0;
    this->airline = "";
}
Flight::Flight(DSString headCity) {
    this->FlightPath = headCity;
    this->cost = 0.0;
    this->time = 0;
    this->airline = "";
}
Flight::Flight(DSString FlightPath, float cost, int time,  DSString airline) {
    this->FlightPath = FlightPath;
    this->cost = cost;
    this->time = time;
    this->airline = airline;
}
bool Flight::operator==(const Flight &rhs) const {
    if (this->FlightPath == rhs.getFlightPath() && this->time == rhs.getTime() && this->cost == rhs.getCost() && this->airline == rhs.getAirline()) {
        return true;
    }
    else return false;
}
DSString Flight::getFlightPath() const {
    return this->FlightPath;
}
float Flight::getCost() const {
    return this->cost;
}
int Flight::getTime() const {
    return this->time;
}
DSString Flight::getAirline() const {
    return this->airline;
}
void Flight::setFlightPath(DSString newFlightPath) {
    this->FlightPath = newFlightPath;
}
void Flight::setCost(float newCost) {
    this->cost = newCost;
}
void Flight::setTime(int newTime) {
    this->time = newTime;
}

void Flight::setAirline(DSString newAirline) {
    this->airline = newAirline;
}
void Flight::printFlight() {
    cout << "To: " << this->FlightPath << endl;
    cout << "Cost: " << this->cost << endl;
    cout << "Time: " << this->time << endl;
    cout << "Airline: " << this->airline << endl;
}