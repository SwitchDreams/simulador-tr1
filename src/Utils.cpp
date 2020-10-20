#include <cstdint>
#include <iostream>
#include "../include/Utils.hpp"

int printMenu() {

    int tipo_codigo;

    std::cout << std::endl << "Tipos de codificação: " << std::endl << std::endl;
    std::cout << "0) Codificação Binária" << std::endl;
    std::cout << "1) Codificação Manchester" << std::endl;
    std::cout << "2) Codificação Manchester Diferencial" << std::endl << std::endl;
    std::cout << "Digite o tipo de codificação que iremos utilizar: ";
    std::cin >> tipo_codigo;
    return tipo_codigo;
}

void setBit(uint8_t *A, unsigned int k) {
    A[k / BIT_SIZE] |= 1 << (k % BIT_SIZE);  // Set the bit at the k-th position in A[i]
}

void clearBit(uint8_t *A, unsigned int k) {
    A[k / BIT_SIZE] &= ~(1 << (k % BIT_SIZE));
}

int getBit(uint8_t *A, unsigned int k) {
    return ((A[k / BIT_SIZE] & (1 << (k % BIT_SIZE))) != 0);
}

uint8_t *stringToBinary(const std::string &mensagem) {
    auto array = (uint8_t *) malloc(mensagem.length() * sizeof(uint8_t));
    int cont = 0;
    for (char letra : mensagem) {
        array[cont] = letra;
        cont++;
    }
    return array;
}

void printBinaryArray(uint8_t *array) {
    for (unsigned int i = 0; i < sizeof(array); i++) {
        for (unsigned int j = 0; j < 8; j++) {
            std::cout << getBit(&array[i], j);
        }
    }
}

