#include "catch.hpp"
#include "Path.h"

TEST_CASE("My Path class", "[Path]") {

    Path path1;
    Path path2;
    Path path3;

    SECTION("Testing constructor") {
        REQUIRE(path1.getFlights().vectorSize() == 0);
        REQUIRE(path1.getTotalTime() == 0);
        REQUIRE(path1.getTotalCost() == 0.0);
    }

    Flight test1("Dallas");
    Flight test2("Austin",98.0,47,"Spirit");
    Flight test3("Houston",101.0,51,"Spirit");
    Flight test5("Houston",95.0,39,"United");

    path2.addFlightToPath(test1);
    path2.addFlightToPath(test2);
    path2.addFlightToPath(test5);
    path3.addFlightToPath(test1);
    path3.addFlightToPath(test3);

    path2.finalizePath();
    path3.finalizePath();

    SECTION("Testing addFlightToPath") {
        REQUIRE(path2.getFlights()[0] == test5);
        REQUIRE(path2.getFlights()[1] == test2);
        REQUIRE(path2.getFlights()[2] == test1);
        REQUIRE(path3.getFlights()[0] == test3);
        REQUIRE(path3.getFlights()[1] == test1);
        REQUIRE(path2.getTotalCost() == 212.0);
        REQUIRE(path2.getTotalTime() == 151);
        REQUIRE(path3.getTotalCost() == 101.0);
        REQUIRE(path3.getTotalTime() == 51);
    }

}

