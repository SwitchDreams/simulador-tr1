#include <iostream>
#include "../include/BitArray.hpp"

using namespace std;

BitArray::BitArray(const std::string &mensagem) {
    this->container = (uint8_t *) calloc(mensagem.length(), sizeof(uint8_t));
    this->lenght = mensagem.length();
    int cont = 0;

    for (char letra : mensagem) {
        this->container[cont] = letra;
        cont++;
    }
}

BitArray::~BitArray() {
    free(container);
}

void BitArray::setBit(unsigned int k) {
    container[k/BIT_SIZE] |= 1 << (k % BIT_SIZE);
}

void BitArray::clearBit(unsigned int k) {
    container[k / BIT_SIZE] &= ~(1 << (k % BIT_SIZE));
}

int BitArray::operator [] (unsigned int k) {
    return (container[k / BIT_SIZE] & (1 << (k % BIT_SIZE))) != 0;
}

void BitArray::print() {
    for (unsigned int i = 0; i < this->lenght; i++) {
        for (unsigned int j = 0; j < BIT_SIZE; j++) {
            cout << (*this)[j];
        }
    }
    cout << endl;
}