#include <iostream>
#include "../include/BitArray.hpp"
#include <cmath>
using namespace std;

BitArray::BitArray(const string &mensagem) {
    // Aloca o espaço de memória para o container com todos valores 0
    this->container = (uint8_t *) calloc(mensagem.length(), sizeof(uint8_t));
    this->lenght = mensagem.length(); // Armazena o tamanho da mensagem
    int cont = 0;
    // Para cada letra da mensagem
    for (char letra : mensagem) {
        this->container[cont] = letra; // Armazena o ascii no container
        cont++;
    }
}

BitArray::BitArray(int tam) {
    int numBytes = ceil( (float) tam / BYTE_SIZE); // Aproxima a quantidade de bytes para cima

    // Aloca o espaço de memória para o container com todos valores 0
    this->container = (uint8_t *) calloc(numBytes, sizeof(uint8_t));
    this->lenght = numBytes; // Armazena o tamanho da mensagem
}

BitArray::~BitArray() {
    free(this->container); // Libera o espaço de memória do container
}

unsigned int BitArray::getByte(uint8_t posicao) {
    return this->container[posicao];
}


unsigned int BitArray::getCabecalho() {
    return this->container[0];
}

unsigned int BitArray::tam() {
    return this->lenght;
}

void BitArray::setBit(unsigned int k) {
    /* Atribui 1 a posição k do array de bits usando um OR entre uma máscara com os valores 0, com exeção da posição
     * de atribuição;
     */
    container[k / BYTE_SIZE] |= 1 << (k % BYTE_SIZE);
}

void BitArray::clearBit(unsigned int k) {
    /* Atribui 0 a posição k do array de bits usando um AND entre uma máscara com os valores 1, com exeção da posição
    * de atribuição;
    */
    container[k / BYTE_SIZE] &= ~(1 << (k % BYTE_SIZE));
}

int BitArray::operator[](unsigned int k) {
    /* Verifica o valor o valor da posição k fazendo um AND com uma máscara com os valores 0, com exeção da posição
     * de verificação e depois comparando o valor com 0;
     */
    return (container[k / BYTE_SIZE] & (1 << (k % BYTE_SIZE))) != 0;
}

void BitArray::operator=(const BitArray &ba) {
    // Copia as informações de &ba para *this
    lenght = ba.lenght;
    for (int i = 0; i < ba.lenght; i++) {
        container[i] = ba.container[i];
    }
}

string BitArray::toString() {
    // Para cada elemento do array (um byte), converte para char e coloca no final da string de retorno
    string message;
    for (int byte = 0; byte < this->lenght; byte++) {
        message.push_back((char) this->container[byte]);
    }

    return message;
}

void BitArray::print() {
    // Para cada bit do array
    for (unsigned int i = 0; i < this->lenght; i++) {
        for (int j = BYTE_SIZE - 1; j >= 0; j--) {
            cout << (*this)[i * 8 + j]; // Printa o bit no terminal
        }
        cout << " ";
    }
    cout << endl;
}

unsigned int BitArray::contBitsOne() {
    unsigned int cont = 0;
    unsigned int tamBits = this->tam() * BYTE_SIZE;
    for (unsigned int i = 0; i < tamBits; i++) {
        if ((*this)[i] == 1) {
            cont++;
        }
    }
    return cont;
}

void BitArray::copyBits(BitArray *array) {
    for (unsigned int i = 0; i < this->lenght * BYTE_SIZE; i++) {
        if ((*array)[i]) {
            setBit(i);
        } else {
            clearBit(i);
        }
    }
}

