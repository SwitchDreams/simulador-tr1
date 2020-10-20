#define CATCH_CONFIG_MAIN

#include "../../lib/catch.hpp"
#include "../../include/Utils.hpp"


TEST_CASE("setBit") {
    auto *vector = (uint8_t *) calloc(1, sizeof(uint8_t)); // 0000 0000
    setBit(vector, 0); // 0000 0001
    REQUIRE(*vector == 1);
}

TEST_CASE("clearBit") {
    auto *vector = (uint8_t *) malloc(sizeof(uint8_t));
    vector[0] = 255; // 1111 1111
    clearBit(vector, 0); // 1111 1110
    REQUIRE(*vector == 254);
}

TEST_CASE("getBit") {
    auto *vector = (uint8_t *) malloc(sizeof(uint8_t));
    vector[0] = 255; // 1111 1111
    REQUIRE(getBit(vector, 0) == 1);
}