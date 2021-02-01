#include "catch.hpp"
#include "DSAdjacencyList.h"

TEST_CASE("My Adjacency List class", "[DSAdjacencyList]") {

    DSAdjacencyList adjList;
    DSString Dallas("Dallas");
    DSString Austin("Austin");
    DSString Houston("Houston");
    DSString Chicago("Chicago");
    adjList.addFlight(Dallas);
    adjList.addFlight(Austin);
    adjList.addFlight(Houston);
    adjList.addFlight(Chicago);

    Flight one("Dallas -> Austin", 98, 47, "Spirit");
    Flight two("Dallas -> Austin", 98, 59, "American");
    Flight three("Austin -> Houston", 95, 39, "United");
    Flight four("Dallas -> Houston", 101, 51, "Spirit");
    Flight five("Austin -> Chicago", 144, 192, "American");
    Flight oneSwap("Austin -> Dallas", 98, 47, "Spirit");
    Flight twoSwap("Austin -> Dallas", 98, 59, "American");
    Flight threeSwap("Houston -> Austin", 95, 39, "United");
    Flight fourSwap("Houston -> Dallas", 101, 51, "Spirit");
    Flight fiveSwap("Chicago -> Austin", 144, 192, "American");

    adjList[Dallas].insert(one, adjList[Dallas].listSize);
    adjList[Dallas].insert(two, adjList[Dallas].listSize);
    adjList[Dallas].insert(four, adjList[Dallas].listSize);
    adjList[Austin].insert(oneSwap, adjList[Austin].listSize);
    adjList[Austin].insert(twoSwap, adjList[Austin].listSize);
    adjList[Austin].insert(three, adjList[Austin].listSize);
    adjList[Austin].insert(five, adjList[Austin].listSize);
    adjList[Houston].insert(threeSwap, adjList[Houston].listSize);
    adjList[Houston].insert(fourSwap, adjList[Houston].listSize);
    adjList[Chicago].insert(fiveSwap, adjList[Chicago].listSize);

    DSString test1("test1");
    DSString test2("test2");
    DSString test3("test3");
    DSString test4("test4");
    DSString test5("test5");
    DSString test6("test6");
    DSString test7("test7");
    DSString test8("test8");
    DSString test9("test9");
    DSString test10("test10");
    adjList.addFlight(test1);
    adjList.addFlight(test2);
    adjList.addFlight(test3);
    adjList.addFlight(test4);
    adjList.addFlight(test5);
    adjList.addFlight(test6);
    adjList.addFlight(test7);
    adjList.addFlight(test8);
    adjList.addFlight(test9);
    adjList.addFlight(test10);

    SECTION("Testing population of list") {
        REQUIRE(adjList[Dallas][0].getFlightPath() == "Dallas");
        REQUIRE(adjList[Dallas][0].getTime() == 0);
        REQUIRE(adjList[Dallas][0].getCost() == 0.0);
        REQUIRE(adjList[Dallas][0].getAirline() == "");
        REQUIRE(adjList[Dallas][1].getFlightPath() == "Dallas -> Austin");
        REQUIRE(adjList[Dallas][1].getTime() == 47.0);
        REQUIRE(adjList[Dallas][1].getCost() == 98);
        REQUIRE(adjList[Dallas][1].getAirline() == "Spirit");
        REQUIRE(adjList[Austin][3].getFlightPath() == "Austin -> Houston");
        REQUIRE(adjList[Austin][3].getTime() == 39.0);
        REQUIRE(adjList[Austin][3].getCost() == 95);
        REQUIRE(adjList[Austin][3].getAirline() == "United");
        REQUIRE(adjList[test1][0].getFlightPath() == "test1");
        REQUIRE(adjList[test2][0].getFlightPath() == "test2");
        REQUIRE(adjList[test3][0].getFlightPath() == "test3");
        REQUIRE(adjList[test4][0].getFlightPath() == "test4");
        REQUIRE(adjList[test5][0].getFlightPath() == "test5");
        REQUIRE(adjList[test6][0].getFlightPath() == "test6");
        REQUIRE(adjList[test7][0].getFlightPath() == "test7");
        REQUIRE(adjList[test8][0].getFlightPath() == "test8");
        REQUIRE(adjList[test9][0].getFlightPath() == "test9");
        REQUIRE(adjList[test10][0].getFlightPath() == "test10");
    }

    SECTION("Testing doesHeadCityExist") {
        REQUIRE(adjList.doesHeadCityExist(Dallas));
        REQUIRE(adjList.doesHeadCityExist(Chicago));
        REQUIRE(!adjList.doesHeadCityExist("Baltimore"));
        REQUIRE(!adjList.doesHeadCityExist("Philly"));
        REQUIRE(!adjList.doesHeadCityExist(""));
    }

    SECTION("Testing operator[int location]") {
        REQUIRE(adjList[0][0] == adjList[Dallas][0]);
        REQUIRE(adjList[2][2].getFlightPath() == "Houston -> Dallas");
        REQUIRE(adjList[3][1].getCost() == 144.0);
        //REQUIRE(adjList[-1][0].getTime() == 0); // Expect this to cause a seg fault and it does, printing an error message.
    }

    DSStack<Flight> flightStack;
    flightStack.push(one);
    flightStack.push(two);

    SECTION("Testing searchStack") {
        REQUIRE(adjList.searchStack(flightStack, one));
        REQUIRE(adjList.searchStack(flightStack, two));
        REQUIRE(!adjList.searchStack(flightStack, three));
    }

    SECTION("Testing searchStackForHeadCity") {
        REQUIRE(adjList.searchStackForHeadCity(flightStack, one.getFlightPath()));
        REQUIRE(adjList.searchStackForHeadCity(flightStack, two.getFlightPath()));
        REQUIRE(!adjList.searchStackForHeadCity(flightStack, three.getFlightPath()));
    }

    SECTION("Testing getSourceIndex") {
        REQUIRE(adjList.getSourceIndex("Dallas") == 0);
        REQUIRE(adjList.getSourceIndex("Austin") == 1);
        REQUIRE(adjList.getSourceIndex("Houston") == 2);
        REQUIRE(adjList.getSourceIndex("Chicago") == 3);
        REQUIRE(adjList.getSourceIndex("Minneapolis") == -1);
    }

}


