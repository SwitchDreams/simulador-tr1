#include "../../lib/catch.hpp"
#include "../../include/BitArray.hpp"


TEST_CASE("Test operator []") {
    BitArray bitArray = BitArray("A"); // 0100 0001 -> 1000 0010
    REQUIRE(bitArray[6] == 1);
}

