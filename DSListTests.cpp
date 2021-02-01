#include "catch.hpp"
#include "DSList.h"
#include "DSString.h"
#include "Flight.h"

TEST_CASE("My list class", "[DSList]") {

    DSList<int> intList;
    DSList<DSString> DSStringList;

    SECTION("Default constructor") {
        REQUIRE(intList.head == nullptr);
        REQUIRE(intList.tail == nullptr);
        REQUIRE(intList.listSize == 0);
        REQUIRE(DSStringList.head == nullptr);
        REQUIRE(DSStringList.tail == nullptr);
        REQUIRE(DSStringList.listSize == 0);
    }

    for (int i = 1; i < 6; i++) {
        intList.insert(i,i-1);
    }
    intList.insert(0,0);
    DSString test1("Test1");
    DSString test2("Test2");
    DSString test3("Test3");
    DSString test4("Test4");
    DSString test5("Test5");
    DSStringList.insert(test1, 0);
    DSStringList.insert(test2, 0);
    DSStringList.insert(test3, 0);
    DSStringList.insert(test4, 0);
    DSStringList.insert(test5, 0);

    SECTION("Testing insert") {
        for(int i = 0; i < 6; i++) {
            REQUIRE(intList[i] == i);
        }
        REQUIRE(DSStringList[0] == "Test5");
        REQUIRE(DSStringList[1] == "Test4");
        REQUIRE(DSStringList[2] == "Test3");
        REQUIRE(DSStringList[3] == "Test2");
        REQUIRE(DSStringList[4] == "Test1");
        //DSStringList.insert("GLHF",-45); // Expect both of these to cause a seg fault, and they do, printing an error message.
        //DSStringList.insert("GG",999);
    }

    DSList<int> copyIntList(intList);
    DSList<DSString> copyDSStringList(DSStringList);

    SECTION ("Copy constructor") {
        for(int i = 0; i < 6; i++) {
            REQUIRE(copyIntList[i] == i);
        }
        REQUIRE(copyDSStringList[0] == "Test5");
        REQUIRE(copyDSStringList[1] == "Test4");
        REQUIRE(copyDSStringList[2] == "Test3");
        REQUIRE(copyDSStringList[3] == "Test2");
        REQUIRE(copyDSStringList[4] == "Test1");
    }

    DSList<int> assignmentOpTestIntList;
    assignmentOpTestIntList = intList;
    DSList<DSString> assignmentOpTestDSStringList = DSStringList;

    SECTION("Assignment operator") {
        for(int i = 0; i < 6; i++) {
            REQUIRE(assignmentOpTestIntList[i] == i);
        }
        REQUIRE(assignmentOpTestDSStringList[0] == "Test5");
        REQUIRE(assignmentOpTestDSStringList[1] == "Test4");
        REQUIRE(assignmentOpTestDSStringList[2] == "Test3");
        REQUIRE(assignmentOpTestDSStringList[3] == "Test2");
        REQUIRE(assignmentOpTestDSStringList[4] == "Test1");
    }

    intList.remove(0);
    intList.remove(2);
    DSStringList.remove(4);
    DSStringList.remove(1);
    DSList<char> charList;
    charList.insert('c',0);
    charList.remove(0);

    SECTION("Testing remove") {
        REQUIRE(intList[0] == 1);
        REQUIRE(intList[2] == 4);
        REQUIRE(DSStringList[1] == "Test3");
        REQUIRE(DSStringList[2] == "Test2");
        REQUIRE(charList.head == nullptr);
        REQUIRE(charList.tail == nullptr);
        //intList.remove(-1);
        //intList.remove(999); // Expect both of these to cause a seg fault and they both do, printing an error message.
    }

    DSList<char> emptyList;
    DSList<string> emptyList2;
    DSList<int> emptyList3;
    DSList<DSString> emptyList4;
    emptyList4.insert("asdf",0);

    SECTION("Testing isEmpty") {
        REQUIRE(emptyList.isEmpty());
        REQUIRE(emptyList2.isEmpty());
        REQUIRE(emptyList3.isEmpty());
        REQUIRE(!emptyList4.isEmpty());
    }

    DSList<int> searchIntList;
    searchIntList.insert(0,0);
    searchIntList.insert(1,0);
    searchIntList.insert(66,0);
    searchIntList.insert(98,0);
    searchIntList.insert(101,0);

    SECTION("Testing search") {
        REQUIRE(searchIntList.search(0) == true);
        REQUIRE(searchIntList.search(1) == true);
        REQUIRE(searchIntList.search(66) == true);
        REQUIRE(searchIntList.search(98) == true);
        REQUIRE(searchIntList.search(101) == true);
        REQUIRE(searchIntList.search(69) == false);
        REQUIRE(searchIntList.search(2) == false);
        REQUIRE(searchIntList.search(99) == false);
        REQUIRE(searchIntList.search(334) == false);
        REQUIRE(searchIntList.search(5) == false);
    }

    DSList<Flight> flightList;
    Flight one("Dallas -> Austin", 98, 47, "Spirit");
    Flight two("Dallas -> Austin", 98, 59, "American");
    Flight four("Dallas -> Houston", 101, 51, "Spirit");
    flightList.insert(four,0);
    flightList.insert(two,0);
    flightList.insert(one,0);

    SECTION("Testing iter") {
        flightList.resetIter();
        REQUIRE(flightList.getIterData() == flightList[1]);
        flightList.moveIter();
        REQUIRE(flightList.getIterData() == flightList[2]);
        flightList.moveIter();
        //flightList.moveIter(); // Expect this to cause a seg fault and it does, printing an error message.
    }


}