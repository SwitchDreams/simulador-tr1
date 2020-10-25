#include <iostream>
#include "../include/BitArray.hpp"

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

BitArray::~BitArray() {
    free(container); // Libera o espaço de memória do container
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

void BitArray::operator= (BitArray &ba) {
    // Copia as informações de &ba para *this
    lenght = ba.lenght;
    for (int i = 0; i < ba.lenght; i++) {
        container[i] = ba.container[i];
    }
}

string BitArray::toString() {
    // Para cada elemento do array (um byte), converte para char e coloca no final da string de retorno
    string message;
    for (u_int8_t byte : this->container) {
        message.push_back((char) byte);
    }

    return message;
}

void BitArray::print() {
    // Para cada bit do array
    for (unsigned int i = 0; i < this->lenght * BYTE_SIZE; i++) {
        cout << (*this)[i]; // Printa o bit no terminal
    }
    cout << endl;
}