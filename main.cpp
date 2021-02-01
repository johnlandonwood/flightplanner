#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "FlightPlanner.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc == 1) {
        Catch::Session().run();
    }
    else {
        FlightPlanner FP;
        FP.planFlights(argv[1],argv[2], argv[3]);
    }
    return 0;
}
