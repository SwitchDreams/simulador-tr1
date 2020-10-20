#define BIT_SIZE 8

#include <string>

int printMenu();

void setBit(uint8_t *A, unsigned int k);

void clearBit(uint8_t *A, unsigned int k);

int getBit(uint8_t *A, unsigned int k);

// Transforma uma string em um array de uint8_t
uint8_t * stringToBinary(const std::string&);

void printBinaryArray(uint8_t*);