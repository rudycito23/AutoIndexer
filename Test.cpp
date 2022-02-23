//
// Created by rrluc on 2/19/2022.
//
#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"

TEST_CASE("Testing DSVector") {
    DSVector<int> test_1;

    SECTION("Size of vector before pushing in data") {
        REQUIRE(test_1.getVectorSize() == 0);
    }
    test_1.pushBack(1);
    SECTION("Size of vector after pushing in data") {
        REQUIRE(test_1.getVectorSize() == 1);
    }
    test_1.pushBack(23);
    test_1.pushBack(214);
    test_1.pushBack(305);
    test_1.pushBack(323);
    for (int i = 0; i < 20; ++i) {
        test_1.pushBack(i);
    }
    SECTION("Testing resize function") {
        REQUIRE(test_1.getVectorSize() == 25);
        REQUIRE(test_1[0] == 1);
        REQUIRE(test_1[3] == 305);
        REQUIRE(test_1[24] == 19);
    }
}


