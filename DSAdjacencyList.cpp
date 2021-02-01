#include "DSAdjacencyList.h"
#include <iostream>
#include <fstream>

DSAdjacencyList::DSAdjacencyList() {};
void DSAdjacencyList::addFlight(Flight flight) {
    DSList<Flight> newPaths;
    newPaths.insert(flight, newPaths.listSize);
    this->cities.pushBack(newPaths);
}
DSList<Flight>& DSAdjacencyList::operator[](int location) {
    return cities[location];
}
DSVector<DSList<Flight>>& DSAdjacencyList::getCities() {
    return this->cities;
}
DSList<Flight>& DSAdjacencyList::operator[](const DSString headCityName) {
    for (int i = 0; i < this->cities.vectorSize(); i++) {
        if (cities[i].head->data.getFlightPath() == headCityName) {
            return cities[i];
        }
    }
}
void DSAdjacencyList::populateList(ifstream &input) { // Populate the adjacency list according to the lines in the input file.
    char* buffer = new char[80];
    int numLines = 0;
    DSString startingCity("");
    DSString destinationCity("");
    DSString arrow(" -> ");
    int tempTime = 0;
    float tempCost = 0.0;
    DSString tempAirline("");
    while(input.getline(buffer, 100)) {
        DSString line(buffer);
        int start = 0;
        int pipeCtr = 0;
        DSString flightPath("");
        DSString flightPathSwap("");
        if (!isalpha(line[0])) {
            numLines = stoi(line.c_str());
        }
        else {
            for (int i = 0; i < line.getLength(); i++) {
                if (line[i] == '|') {
                    pipeCtr++;
                    if (pipeCtr == 1) { // Set the new Flight object's starting city
                        startingCity = line.substring(start, i - start);
                        if (!this->doesHeadCityExist(startingCity)) { // If the city does not already have its own DSList in the adjacency list, create one for it.
                            this->addFlight(startingCity);
                        }
                    }
                    else if (pipeCtr == 2) { // Set the new Flight object's destination city
                        destinationCity = line.substring(start, i - start);
                        if (!this->doesHeadCityExist(destinationCity)) { // If the city does not already have its own DSList in the adjacency list, create one for it.
                            this->addFlight(destinationCity);
                        }
                    }
                    else if (pipeCtr == 3) { // Set the new flight object's cost
                        tempCost = stof(line.substring(start, i - start).c_str());
                    }
                    else if (pipeCtr == 4) { // Set the new flight object's time
                        tempTime = stoi(line.substring(start, i - start).c_str());
                    }
                    start = i + 1;
                }
                else if (i == line.getLength() - 1) { // Set the new flight object's airline
                    tempAirline = line.substring(start, i);
                }
            }
            Flight temp1(startingCity);
            Flight temp2(destinationCity);
            flightPath = startingCity;
            flightPathSwap = destinationCity;
            Flight newFlight(flightPath, tempCost, tempTime, tempAirline);
            Flight newFlightSwap(flightPathSwap, tempCost, tempTime, tempAirline);
            if (!this->cities[temp1].search(flightPathSwap)) {
                this->cities[temp1].insert(newFlightSwap, this->cities[temp1].listSize);
            }
            if (!this->cities[temp2].search(flightPath)) {
                this->cities[temp2].insert(newFlight, this->cities[temp2].listSize);
            }
        }
    }
    delete []buffer;
}
void DSAdjacencyList::print() {
    cout << "------------------------------" << endl;
    for (int i = 0; i < cities.vectorSize(); i++) {
        cities[i].printFlightList();
    }
}
bool DSAdjacencyList::doesHeadCityExist(DSString headCityName) {
    for (int i = 0; i < cities.vectorSize(); i++) {
        if (cities[i].head->data.getFlightPath() == headCityName) {
            return true;
        }
    }
    return false;
}
bool DSAdjacencyList::searchStack(DSStack<Flight> stack, Flight key) {
    if (stack.getStackList().search(key)) {
        return true;
    }
    else return false;
}
bool DSAdjacencyList::searchStackForHeadCity(DSStack<Flight> stack, Flight key) {
    if (stack.getStackList().search2(key.getFlightPath())) {
        return true;
    }
    else return false;
}
int DSAdjacencyList::getSourceIndex(DSString source) {
    for (int i = 0; i < cities.vectorSize(); i++) {
        if (cities[i].head->data.getFlightPath() == source) {
            return i;
        }
    }
    return -1;
}