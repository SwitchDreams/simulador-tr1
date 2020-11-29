#include <iostream>
#include "../include/CamadaEnlaceTransmissora.hpp"
#include "../include/Utils.hpp"

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


    for(unsigned int i = 0; i < quadro->tam(); i++) {
        uint8_t byte = 0; 
        for(unsigned int j = 0; j < BYTE_SIZE ; j++) {
            byte |= (*quadro)[i*8 + j] << j;
        }

        quadroComFlags.push_back(BYTE_FLAG); // Adicionando a Flag antes de cada byte
        if(byte == BYTE_FLAG or byte == BYTE_ESC) {
            // Acrescentar o byte 'ESC' antes do ESC ou Flag no campo de carga útil
            quadroComFlags.push_back(BYTE_ESC);
            quadroComFlags.push_back(byte);
            quadroComFlags.push_back(BYTE_FLAG); // Adicionando a Flag após cada byte
        } else {
            quadroComFlags.push_back(byte);
            quadroComFlags.push_back(BYTE_FLAG); // Adicionando a Flag após cada byte
        }
    }


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
    std::cout << "Mensagem codificada: ";
    std::cout << quadroCompleto->toString() << std::endl;
    std::cout << std::endl;

    return quadroCompleto;
};

BitArray *CETInsercaoBits::execute(BitArray *quadro) {

    std::vector<uint8_t> quadroDeBitsComFlags;

    
    int numBits = 0;

    for (unsigned int i = 0; i < quadro->tam(); i++) {

        insereBytesComoBits(BIT_FLAG, &quadroDeBitsComFlags);
        for (unsigned int j = 0; j < TAM_QUADRO; j++) {
            uint8_t bit = (*quadro)[i*TAM_QUADRO + j];

            if (bit) {
                numBits++;

                quadroDeBitsComFlags.push_back(bit);
                if (numBits == 5) {
                    quadroDeBitsComFlags.push_back(0);
                    numBits = 0;
                }
            } else {
                numBits = 0;
                quadroDeBitsComFlags.push_back(bit);
            }
        }
        insereBytesComoBits(BIT_FLAG, &quadroDeBitsComFlags);
    }

    // Criando bitArray com mais um byte para alocar espaços para os zeros inseridos
    BitArray* quadroDeBits;
    if (quadroDeBitsComFlags.size() % 8 == 0) {
        quadroDeBits = new BitArray((int) quadroDeBitsComFlags.size());
    } else {
        quadroDeBits = new BitArray((int) (quadroDeBitsComFlags.size() + BYTE_SIZE));
    }

    // Preenche o bitArray
    for (unsigned int i = 0; i < quadroDeBitsComFlags.size() * BYTE_SIZE; i++) {
        uint8_t bit = quadroDeBitsComFlags[i];
        bit ? quadroDeBits->setBit(i) : quadroDeBits->clearBit(i);
    }

    std::cout << "A flag é: " << "01111110" << std::endl;
    std::cout << std::endl << "Inserção de Bits: ";
    quadroDeBits->print();
    std::cout << std::endl;

    return quadroDeBits;
};