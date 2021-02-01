#include "catch.hpp"
#include "DSStack.h"
#include "DSString.h"

TEST_CASE("My stack class", "[DSStack]") {

    DSStack<int> intStack;
    intStack.push(4);
    intStack.push(3);
    intStack.push(2);
    intStack.push(1);
    intStack.push(0);

    SECTION("Testing push") {
        for (int i = 0; i < 5; i++) {
            REQUIRE(intStack[i] == i);
        }
    }

    intStack.pop();
    intStack.pop();
    intStack.pop();

    SECTION("Testing pop") {
        REQUIRE(intStack[0] == 3);
        REQUIRE(intStack[1] == 4);
    }

    DSStack<DSString> DSStringStack;
    DSStringStack.push("Dallas");
    DSStringStack.push("Austin");
    DSStringStack.push("New Braunfels");
    DSStringStack.push("Houston");
    DSStringStack.push("Waxahachie");
    DSStack<char> emptyStack;

    SECTION("Testing peek") {
        REQUIRE(DSStringStack.peek() == "Waxahachie");
        DSStringStack.pop();
        REQUIRE(DSStringStack.peek() == "Houston");
        DSStringStack.pop();
        REQUIRE(DSStringStack.peek() == "New Braunfels");
        DSStringStack.pop();
        REQUIRE(DSStringStack.peek() == "Austin");
        DSStringStack.pop();
        REQUIRE(DSStringStack.peek() == "Dallas");
        emptyStack.peek(); // will cout ERROR: Stack empty, cannot peek
        //REQUIRE(emptyStack.peek() == 0); // will cout ERROR: Stack empty, cannot peek
    }

    SECTION("Testing getSize") {
        REQUIRE(intStack.getSize() == 2);
        REQUIRE(DSStringStack.getSize() == 5);
    }

    DSStack<double> emptyStack2;

    SECTION("Testing isEmpty") {
        REQUIRE(!intStack.isEmpty());
        REQUIRE(!DSStringStack.isEmpty());
        REQUIRE(emptyStack.isEmpty());
        REQUIRE(emptyStack2.isEmpty());
    }

    Flight one("Dallas -> Austin", 98, 47, "Spirit");
    Flight two("Dallas -> Austin", 98, 59, "American");
    Flight three("Austin -> Houston", 95, 39, "United");

    DSStack<Flight> flightStack;
    flightStack.push(one);
    flightStack.push(two);

    SECTION("Testing getStackList") {
        REQUIRE(flightStack.getStackList().search(one));
        REQUIRE(flightStack.getStackList().search(two));
        REQUIRE(!flightStack.getStackList().search(three));
    }

}