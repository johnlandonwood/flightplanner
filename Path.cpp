#include <iomanip>
#include "Path.h"



Path::Path() {
    this->totalTime = 0;
    this->totalCost = 0.0;
}
void Path::addFlightToPath(Flight flight) {
    if (this->flights.search(flight)) goto finish; // I had to jerry rig this function with the goto because I was having problems with seemingly inexplicable duplicates being added to flights vector
    this->flights.pushBack(flight);
    this->totalCost += flight.getCost();
    this->totalTime += flight.getTime();
    if (this->flights.vectorSize() > 2) {
        this->totalCost += 19.00;
        this->totalTime += 43;
    }
    finish:
    int dummy;
}
void Path::finalizePath() { // Reverse flights array and finish computing totalTime
    int ctr = 0;
    this->flights.reverse(0, this->flights.vectorSize() - 1);
    for (int i = 1; i < flights.vectorSize() - 1; i++) {
        if (this->flights[i+1].getAirline() != this->flights[i].getAirline()) {
            ctr++;
        }
    }
    this->totalTime += ctr * 22;
}
DSVector<Flight>& Path::getFlights() {
    return this->flights;
}
int Path::getTotalTime() {
    return this->totalTime;
}
float Path::getTotalCost() {
    return this->totalCost;
}
void Path::print() {
    DSString arrow(" -> ");
    for (int i = 0; i < flights.vectorSize(); i++) {
        if (i == 0) {
            cout << flights[i].getFlightPath() << arrow;
        }
        else if (i == flights.vectorSize() - 1) {
            cout << flights[i].getFlightPath() << ".";
        }
        else {
            cout << flights[i].getFlightPath() << arrow;
        }
    }
    cout << " Time: " << totalTime << " " << "Cost: " << std::fixed << std::setprecision(2) << totalCost << endl;
    cout << "Airlines taken:" << endl;
    for (int i = 0; i < flights.vectorSize(); i++) {
        if (flights[i].getAirline() != "") {
            cout << flights[i].getAirline() << endl;
        }
    }
}
void Path::printPath(ofstream& output) {
    DSString arrow(" -> ");
    for (int i = 0; i < flights.vectorSize(); i++) {
        if (i == 0) {
            output << flights[i].getFlightPath() << arrow;
        }
        else if (i == flights.vectorSize() - 1) {
            output << flights[i].getFlightPath() << ".";
        }
        else {
            output << flights[i].getFlightPath() << arrow;
        }
    }
    output << " Time: " << totalTime << " " << "Cost: " << std::fixed << std::setprecision(2) << totalCost << endl;
    output << "Airlines taken:" << endl;
    for (int i = 0; i < flights.vectorSize(); i++) {    // I apologize for the fact that these are on different lines.
        if (flights[i].getAirline() != "") {            // It would look way better if they were on the same line, but I have been having extremely frustrating
            output << flights[i].getAirline() << endl;  // text wrapping issues with printing the airline, and this was the only way my output could be legible.
        }
    }

}