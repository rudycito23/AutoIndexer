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
    SECTION("test findIndex function") {
        REQUIRE(test_1.findIndex(1) == 0);
        REQUIRE(test_1.findIndex(305) == 3);
        REQUIRE(test_1.findIndex(19) == 24);
    }
    test_1.removeDataFromIndex(3);
    test_1.removeDataFromIndex(0);
    test_1.removeDataFromIndex(1);
    SECTION("test removeDataFromIndex") {
        REQUIRE(test_1[3] != 305);
        REQUIRE(test_1[0] != 1);
        REQUIRE(test_1[1] != 23);
        REQUIRE(test_1[0] == 23);
        REQUIRE(test_1[1] == 323);
        REQUIRE(test_1.getVectorSize() == 22);
    }
    DSVector<int> vector_2 = test_1;
    SECTION("test copy constructor") {
        REQUIRE(vector_2[1] == 323);
        REQUIRE(vector_2[21] == 19);
        REQUIRE(vector_2.getVectorSize() == 22);
    }
    DSVector<int> vector_3;
    vector_3 = vector_2;
    SECTION("test assignment operator") {
        REQUIRE(vector_3[0] == 23);
        REQUIRE(vector_3[2] == 0);
        REQUIRE(vector_3[21] == 19);
    }
}

TEST_CASE("DSString") {
    DSString line("data structures is a difficult class.");
    DSString keyword("data structures");
    DSString keyword2("rudy");
    DSString keyword3("class");
    SECTION("testing does_contain_keywords function") {
        REQUIRE(line.does_contain_keyword(keyword) == true);
        REQUIRE(line.does_contain_keyword(keyword2) == false);
        REQUIRE(line.does_contain_keyword(keyword3) == true);
    }
}


