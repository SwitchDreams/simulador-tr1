#include <iostream>
#include "../include/CamadaEnlaceReceptora.hpp"

BitArray *CERContagemCaracteres::execute(BitArray *quadro) {
    std::cout << "Decodificação Contagem de Caracteres: ";

    // Tamanho do quadro em BYTES
    int tamanhoQuadro = (int) quadro->getCabecalho();

    // Cria um novo quadro sem o cabeçalho
    auto *quadroSemCabecalho = new BitArray(tamanhoQuadro * BYTE_SIZE);

    for (int i = 0; i < tamanhoQuadro * BYTE_SIZE; i++) {
        // Começa do segundo byte porconta do cabeçalho
        if ((*quadro)[i + BYTE_SIZE]) {
            quadroSemCabecalho->setBit(i);
        } else {
            quadroSemCabecalho->clearBit(i);
        }

    }

    quadroSemCabecalho->print();
    std::cout << std::endl;
    return quadroSemCabecalho;
};

BitArray *CERInsercaoBytes::execute(BitArray *quadro) {
    
    BitArray* quadroDecodificado = new BitArray(quadro->tam() * BYTE_SIZE); // Verificar o tam
    uint8_t byte = 0, previousByte, indice = 0; 

    for(unsigned int i = 0; i < quadro->tam(); i++) {
        
        previousByte = byte; // Salvando o byte anterior para verificações

        // Pegando o byte
        for(unsigned int j = 0; j < BYTE_SIZE ; j++) {
            byte |= (*quadro)[i*8 + j] << j;
        }
        
        // Verificando se deve-se descartar a informação
        if(byte == BYTE_FLAG and previousByte != BYTE_ESC) {
            // O valor é uma flag, pois o anterior não é o byte de escape
            continue;
        } else if (byte == BYTE_ESC and previousByte != BYTE_ESC) {
            // O valor não é do campo de carga útil
            // É um escape, pois o anterior não é o byte de escape
            continue;
        }
        
        // Salvando no quadro decodificado
        for(int k = 0; k < BYTE_SIZE; k++) {
            uint8_t bit = byte >> k & BIT_1;   
            if(bit) {
                quadroDecodificado->setBit(indice*8 + k);
            } else {
                quadroDecodificado->clearBit(indice*8 + k);
            }
        }
        indice++;
    }
    
    std::cout << "Decodificação da Inserção de Byte: ";
    quadroDecodificado->print();
    std::cout << std::endl;

    return quadroDecodificado;
};

BitArray *CERInsercaoBits::execute(BitArray *quadro) {
    return quadro;
};