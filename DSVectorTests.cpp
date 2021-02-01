#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"
#include "Request.h"

TEST_CASE("My vector class", "[DSVector]") {

    DSVector<int> intVector;
    DSVector<DSString> DSStringVector(0);

    SECTION("Default constructors") {
        REQUIRE(intVector.vectorSize() == 0);
        REQUIRE(intVector.vectorCapacity() == 10);
        REQUIRE(DSStringVector.vectorSize() == 0);
        REQUIRE(DSStringVector.vectorCapacity() == 10);
    }

    DSString String1("String1");
    DSString String2("String2");
    DSString String3("String3");
    DSString String4("String4");
    DSString String5("String5");
    DSString String6("String6");
    DSString String7("String7");
    DSString String8("String8");
    DSString String9("String9");
    DSString String10("String10");
    DSString String11("String11");
    DSString String12("String12");
    DSString String13("String13");
    DSStringVector.pushBack(String1);
    DSStringVector.pushBack(String2);
    DSStringVector.pushBack(String3);
    DSStringVector.pushBack(String4);
    DSStringVector.pushBack(String5);
    DSStringVector.pushBack(String6);
    DSStringVector.pushBack(String7);
    DSStringVector.pushBack(String8);
    DSStringVector.pushBack(String9);
    DSStringVector.pushBack(String10);
    DSStringVector.pushBack(String11);
    DSStringVector.pushBack(String12);
    DSStringVector.pushBack(String13);
    for(int i = 0; i < 20; i++) {
        intVector.pushBack(i);
    }

    SECTION("Testing pushBack") {
        for(int i = 0; i < 20; i++) {
            REQUIRE(intVector[i] == i);
        }
        REQUIRE(DSStringVector[0] == "String1");
        REQUIRE(DSStringVector[1] == "String2");
        REQUIRE(DSStringVector[2] == "String3");
        REQUIRE(DSStringVector[3] == "String4");
        REQUIRE(DSStringVector[4] == "String5");
        REQUIRE(DSStringVector[5] == "String6");
        REQUIRE(DSStringVector[6] == "String7");
        REQUIRE(DSStringVector[7] == "String8");
        REQUIRE(DSStringVector[8] == "String9");
        REQUIRE(DSStringVector[9] == "String10");
        REQUIRE(DSStringVector[10] == "String11");
        REQUIRE(DSStringVector[11] == "String12");
        REQUIRE(DSStringVector[12] == "String13");
        //REQUIRE(DSStringVector[999] == "asdf");
        //REQUIRE(DSStringVector[-21] == "asdf"); // Expect both of these to cause a seg fault and they do, printing an error message.
    }

    DSVector<char> charVector;
    charVector.pushBack('a');
    charVector.pushBack('b');
    charVector.pushBack('c');
    charVector.pushBack('d');
    charVector.pushBack('e');
    charVector.pushAt('x',0);
    charVector.pushAt('y',2);
    charVector.pushAt('z',4);

    SECTION("Testing pushAt") {
        REQUIRE(charVector[0] == 'x');
        REQUIRE(charVector[1] == 'b');
        REQUIRE(charVector[2] == 'y');
        REQUIRE(charVector[3] == 'd');
        REQUIRE(charVector[4] == 'z');
    }

    charVector.popBack();
    charVector.popBack();
    charVector.popBack();
    DSVector<string> stringVector;
    stringVector.pushBack("Hello");
    stringVector.pushBack("Greetings");
    stringVector.pushBack("Salutations");
    stringVector.pushBack("Whattup");
    stringVector.pushBack("Good day");
    stringVector.popBack();
    stringVector.popBack();

    SECTION("Testing popBack") {
        REQUIRE(charVector.vectorSize() == 2);
        REQUIRE(stringVector.vectorSize() == 3);
    }

    DSVector<int> copyIntVector(intVector);
    DSVector<DSString> copyDSStringVector(DSStringVector);

    SECTION("Testing copy constructor") {
        for(int i = 0; i < 20; i++) {
            REQUIRE(copyIntVector[i] == i);
        }
        REQUIRE(copyDSStringVector[0] == "String1");
        REQUIRE(copyDSStringVector[1] == "String2");
        REQUIRE(copyDSStringVector[2] == "String3");
        REQUIRE(copyDSStringVector[3] == "String4");
        REQUIRE(copyDSStringVector[4] == "String5");
        REQUIRE(copyDSStringVector[5] == "String6");
        REQUIRE(copyDSStringVector[6] == "String7");
        REQUIRE(copyDSStringVector[7] == "String8");
        REQUIRE(copyDSStringVector[8] == "String9");
        REQUIRE(copyDSStringVector[9] == "String10");
        REQUIRE(copyDSStringVector[10] == "String11");
        REQUIRE(copyDSStringVector[11] == "String12");
        REQUIRE(copyDSStringVector[12] == "String13");
    }

    DSVector<int> assignmentOperatorIntVector;
    assignmentOperatorIntVector = intVector;

    SECTION("Testing copy assignment operator") {
        for(int i = 0; i < 20; i++) {
            REQUIRE(assignmentOperatorIntVector[i] == i);
        }
    }

    DSVector<char> popTest;
    popTest.pushBack('A');
    popTest.pushBack('B');
    popTest.pushBack('C');
    popTest.pushBack('D');
    popTest.pushBack('E');
    popTest.pushBack('F');
    popTest.pushBack('G');
    popTest.popAt(3);
    popTest.popAt(4);

    SECTION("Testing popAt") {
        REQUIRE(popTest[0] == 'A');
        REQUIRE(popTest[1] == 'B');
        REQUIRE(popTest[2] == 'C');
        REQUIRE(popTest[3] == 'E');
        REQUIRE(popTest[4] == 'G');
    }

    SECTION("Testing search") {
        REQUIRE(popTest.search('E') == true);
        REQUIRE(stringVector.search("Salutations") == true);
        REQUIRE(intVector.search(10) == true);
        REQUIRE(DSStringVector.search("String3") == true);
        REQUIRE(assignmentOperatorIntVector.search(19) == true);
    }

    DSVector<int> sortIntVector;
    DSVector<DSString> sortDSStringVector;

    sortIntVector.pushBack(8);
    sortIntVector.pushBack(50);
    sortIntVector.pushBack(12);
    sortIntVector.pushBack(19);
    sortDSStringVector.pushBack("algorithm");
    sortDSStringVector.pushBack("tree");
    sortDSStringVector.pushBack("binary");
    sortDSStringVector.pushBack("analysis");

    sortIntVector.selectionSort();
    sortDSStringVector.selectionSort();

    SECTION("Testing selectionSort") {
        REQUIRE(sortIntVector[0] == 8);
        REQUIRE(sortIntVector[1] == 12);
        REQUIRE(sortIntVector[2] == 19);
        REQUIRE(sortIntVector[3] == 50);
        REQUIRE(sortDSStringVector[0] == "algorithm");
        REQUIRE(sortDSStringVector[1] == "analysis");
        REQUIRE(sortDSStringVector[2] == "binary");
        REQUIRE(sortDSStringVector[3] == "tree");
    }

    DSString nonExistent("nonExistent");

    SECTION("Testing overloaded [DSString]") {
        REQUIRE(DSStringVector[String5] == "String5");
        REQUIRE(DSStringVector[String8] == "String8");
        REQUIRE(DSStringVector[String11] == "String11");
        //REQUIRE(DSStringVector[nonExistent] == "nonExistent"); // Expect this to cause undefined behavior and it does, printing an error message.
    }

    DSVector<Request> requests;
    Request testReq1("Dallas", "Houston", 'T');
    Request testReq2("Chicago", "Dallas", 'C');
    requests.pushBack(testReq1);
    requests.pushBack(testReq2);

    SECTION("Testing vector of Requests") {
        REQUIRE(requests[testReq1].getSource() == "Dallas");
        REQUIRE(requests[testReq1].getDestination() == "Houston");
        REQUIRE(requests[testReq1].getSortCriteria() == 'T');
        REQUIRE(requests[testReq2].getSource() == "Chicago");
        REQUIRE(requests[testReq2].getDestination() == "Dallas");
        REQUIRE(requests[testReq2].getSortCriteria() == 'C');
    }

}


