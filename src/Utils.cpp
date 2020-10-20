#include <cstdint>
#include "../include/Utils.hpp"

void setBit(uint8_t *A, unsigned int k) {
    A[k / BIT_SIZE] |= 1 << (k % BIT_SIZE);  // Set the bit at the k-th position in A[i]
}

void clearBit(uint8_t *A, unsigned int k) {
    A[k / BIT_SIZE] &= ~(1 << (k % BIT_SIZE));
}

int getBit(uint8_t *A, unsigned int k) {
    return ((A[k / BIT_SIZE] & (1 << (k % BIT_SIZE))) != 0);
}