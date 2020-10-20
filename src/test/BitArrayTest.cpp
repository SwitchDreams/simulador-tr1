#define CATCH_CONFIG_MAIN

#include "../../lib/catch.hpp"
#include "../../include/BitArray.hpp"


TEST_CASE("Test operator []") {
    BitArray bitArray = BitArray("A"); // 0100 0001 -> 1000 0010
    REQUIRE(bitArray[6] == 1);
}

TEST_CASE(".setBit") {
    BitArray bitArray = BitArray("A"); // 0100 0001 -> 1000 0010
    REQUIRE(bitArray[7] == 0);
    bitArray.setBit(7);
    REQUIRE(bitArray[7] == 1);
}

TEST_CASE(".clearBit") {
    BitArray bitArray = BitArray("A"); // 0100 0001 -> 1000 0010
    REQUIRE(bitArray[6] == 1);
    bitArray.clearBit(6);
    REQUIRE(bitArray[6] == 0);
}
