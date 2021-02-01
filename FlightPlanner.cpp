#include <iostream>
#include <fstream>
#include "FlightPlanner.h"
#include "DSStack.h"
#include "DSString.h"
#include "DSAdjacencyList.h"
#include "DSVector.h"
#include "Path.h"
using std::cout;
using std::endl;

FlightPlanner::FlightPlanner() {}

void FlightPlanner::planFlights(char *argv1, char *argv2, char* argv3) {

    std::ifstream input01;
    input01.open(argv1);
    std::ifstream input02;
    input02.open(argv2);
    std::ofstream output;
    output.open(argv3);

    DSAdjacencyList adjList;
    adjList.populateList(input01); // Populate the adjacency list according to the first input file
    DSVector<Request> requests;
    requests.getRequests(input02); // Get the parameters of each request from the second input file
    DSStack<Flight> stack;

    for (int i = 0; i < requests.vectorSize(); i++) { // For each request in the second input file:
        DSString source = requests[i].getSource();
        DSString destination = requests[i].getDestination();
        char sortCriteria = requests[i].getSortCriteria();
        DSVector<Path> paths;
        Flight emptyFlight("null");
        for (int k = 0; k < adjList.getCities().vectorSize(); k++) { // Add a "dummy" node in each list on the adjacency list, to act as nullptr
            adjList[k].insert(emptyFlight, adjList[k].listSize);
            adjList[k].resetIter(); // Initialize all of adjList's iterators
        }
        // Iterative backtracking
        stack.push(adjList[source][0]); // Push source to stack
        while(!stack.isEmpty()) {
            int sourceIndex = adjList.getSourceIndex(stack.peek().getFlightPath());
            if (stack.peek().getFlightPath() == destination) { // If the top of the stack is the destination, store path and pop
                Path newPath;
                DSStack<Flight> copyStack;
                copyStack.getStackList() = stack.getStackList();
                for (int z = 0; z <= copyStack.getSize(); z++) {
                    Flight newFlight = copyStack.peek();
                    newPath.addFlightToPath(newFlight);
                    copyStack.pop();
                }
                newPath.addFlightToPath(source);
                paths.pushBack(newPath);
                stack.pop();
            }
            else {
                if (adjList[sourceIndex].iter->data.getFlightPath() == "null") { // If connection is null, pop stack and reset iter
                    stack.pop();
                    adjList[sourceIndex].resetIter();
                }
                else {
                    if (adjList.searchStackForHeadCity(stack, adjList[sourceIndex].getIterData())) { // If connection is on stack, move iter and continue
                        adjList[sourceIndex].moveIter();
                    }
                    else { // If connection is not on stack, push connection, move iter, go back to top of while loop
                        stack.push(adjList[sourceIndex].getIterData());
                        adjList[sourceIndex].moveIter();
                    }
                }
            }
        }
        // Backtracking finished
        // Now, sort and report the top three paths
        DSString fullSortCriteria("");
        if (sortCriteria == 'C') {
            fullSortCriteria = "(Cost)";
        }
        else if (sortCriteria == 'T') {
            fullSortCriteria = "(Time)";
        }
        if (paths.vectorSize() == 0) {
            output << "Flight " << i + 1 << ": " << source << ", " << destination << " " << fullSortCriteria << endl;
            output << "No paths found from " << source << " to " << destination << "." << endl;
        }
        else {
            for (int m = 0; m < paths.vectorSize(); m++) {
                paths[m].finalizePath();
            }
            output << "Flight " << i + 1 << ": " << source << ", " << destination << " " << fullSortCriteria << endl;
            paths.sortBy(sortCriteria);
            paths.printPaths(output);
            output << endl;
        }
    }

    input01.close();
    input02.close();
    output.close();

}