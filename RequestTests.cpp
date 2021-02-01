#include "catch.hpp"
#include "Request.h"

TEST_CASE("My Request class", "[Request]") {

    Request test1;
    Request test2("Dallas", "Houston", 'T');
    Request test3("Dallas", "Houston", 'T');
    SECTION("Testing constructors") {
        REQUIRE(test1.getSource() == "");
        REQUIRE(test1.getDestination() == "");
        REQUIRE(test1.getSortCriteria() == ' ');
        REQUIRE(test2.getSource() == "Dallas");
        REQUIRE(test2.getDestination() == "Houston");
        REQUIRE(test2.getSortCriteria() == 'T');
    }

    test1.setSource("Chicago");
    test1.setDestination("Dallas");
    test1.setSortCriteria('C');

    SECTION("Testing set methods") {
        REQUIRE(test1.getSource() == "Chicago");
        REQUIRE(test1.getDestination() == "Dallas");
        REQUIRE(test1.getSortCriteria() == 'C');
    }

    SECTION("Testing operator==") {
        REQUIRE(!(test1 == test2));
        REQUIRE((test2 == test3));
    }

}
