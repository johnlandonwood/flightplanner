#include "catch.hpp"
#include "Flight.h"
#include "DSList.h"

TEST_CASE("My Flight class", "[Flight]") {

    Flight default_obj;
    DSString Dallas("Dallas");
    DSString Spirit("Spirit");
    Flight test1("Chicago");
    Flight test2(Dallas, 98.0, 47, Spirit);

    SECTION("Testing constructors") {
        REQUIRE(default_obj.getFlightPath() == "");
        REQUIRE(default_obj.getCost() == 0.0);
        REQUIRE(default_obj.getTime() == 0);
        REQUIRE(default_obj.getAirline() == "");
        REQUIRE(test1.getFlightPath() == "Chicago");
        REQUIRE(test1.getTime() == 0);
        REQUIRE(test1.getCost() == 0.0);
        REQUIRE(test1.getAirline() == "");
        REQUIRE(test2.getFlightPath() == Dallas);
        REQUIRE(test2.getTime() == 47);
        REQUIRE(test2.getCost() == 98.0);
        REQUIRE(test2.getAirline() == Spirit);
    }

    test2.setFlightPath("setting this");
    test2.setTime(1234);
    test2.setCost(147.0);
    test2.setAirline("This airline does not exist. It is purely hypothetical.");

    SECTION("Testing set methods") {
        REQUIRE(test2.getFlightPath() == "setting this");
        REQUIRE(test2.getTime() == 1234);
        REQUIRE(test2.getCost() == 147.0);
        REQUIRE(test2.getAirline() == "This airline does not exist. It is purely hypothetical.");
    }

    Flight default_obj2;

    SECTION("Testing operator==") {
        REQUIRE(!(test2 == test1));
        REQUIRE((default_obj) == (default_obj2));
    }

}
