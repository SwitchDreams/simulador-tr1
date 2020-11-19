#include <iostream>
#include "../include/CamadaEnlaceTransmissora.hpp"

BitArray *CETContagemCaracteres::execute(BitArray *quadro) {
    std::cout << "Contagem de Caracteres: ";

    // Tamanho do quadro em BYTES
    unsigned int tamanhoQuadro = quadro->tam();

    // Adicionando o cabeçalho na mensagem
    auto* quadroComCabecalho = new BitArray((char) tamanhoQuadro + quadro->toString());

    quadroComCabecalho->print();
    std::cout << std::endl;
    return quadroComCabecalho;

};

BitArray *CETInsercaoBytes::execute(BitArray *quadro) {
    std::vector<uint8_t> quadroComFlags;

    quadroComFlags.push_back(BYTE_FLAG);

    for(unsigned int i = 0; i < quadro->tam(); i++) {
        uint8_t byte = 0; 
        for(unsigned int j = 0; j < BYTE_SIZE ; j++) {
            byte |= (*quadro)[i*8 + j] << j;
        }
        if(byte == BYTE_FLAG or byte == BYTE_ESC) {
            // Acrescentar o byte 'ESC' antes do ESC ou Flag no campo de carga útil
            quadroComFlags.push_back(BYTE_ESC);
            quadroComFlags.push_back(byte);
        } else {
            quadroComFlags.push_back(byte);
        }
    }
    quadroComFlags.push_back(BYTE_FLAG);

    BitArray* quadroCompleto = new BitArray(quadroComFlags.size() * BYTE_SIZE);

    for(unsigned int i = 0; i < quadroComFlags.size(); i++) {
        for(unsigned int j=0; j < BYTE_SIZE; j++) {
            uint8_t bit = quadroComFlags[i] >> j & BIT_1;
            if(bit) {
                quadroCompleto->setBit(i*8 + j);
            } else {
                quadroCompleto->clearBit(i*8 + j);
            }
        }
    }

    std::cout << "A flag é: " << "01000000 (@)" << std::endl;
    std::cout << "O ESC é: " << "00100011 (#)" << std::endl;
    std::cout << std::endl << "Inserção de Byte: ";
    quadroCompleto->print();
    std::cout << std::endl;

    return quadroCompleto;
};

BitArray *CETInsercaoBits::execute(BitArray *quadro) {
    return quadro;
};