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
    
    uint8_t byte = 0, previousByte, indice = 0; 
    int lastEscIsData = 0, anterior = 0;
    std::string mensagem;

    for(unsigned int i = 0; i < quadro->tam(); i++) {
        
        previousByte = byte; // Salvando o byte anterior para verificações

        byte = quadro->getByte(i);
        
        anterior = i-1;

        // Verificando se deve-se descartar a informação
        if(byte == BYTE_FLAG and previousByte != BYTE_ESC) {
            // O valor é uma flag, pois o anterior não é o byte de escape
            continue;
        } else if (byte == BYTE_ESC and previousByte != BYTE_ESC) {
            // O valor não é do campo de carga útil
            // É um escape, pois o anterior não é o byte de escape
            continue;
        } else if (byte == BYTE_ESC and previousByte == BYTE_ESC and lastEscIsData != anterior) {
            // O esc anterior não é de dado
            lastEscIsData = i; // Atual é de dado
        } else if ((byte == BYTE_FLAG or byte == BYTE_ESC) and previousByte == BYTE_ESC and lastEscIsData == anterior) {
            // Esc anterior é de dados, atual é esc normal
            continue;
        }

        mensagem += quadro->getByte(i);
    }

    BitArray* quadroDecodificado = new BitArray(mensagem);
    
    std::cout << "Decodificação da Inserção de Byte: ";
    quadroDecodificado->print();
    std::cout << std::endl;

    return quadroDecodificado;
};

BitArray *CERInsercaoBits::execute(BitArray *quadro) {

    // Se o quadro for múltiplo de 3, não houve inserção de bits
    if (quadro->tam() % 3 == 0) {
        std::string mensagem = "";
        for (unsigned int i = 0; i < quadro->tam(); i ++) {
            uint8_t byte = quadro->getByte(i);

            if (byte != BIT_FLAG) {
                mensagem.push_back(byte);
            }
        }

        auto bitArray = new BitArray(mensagem);
        return bitArray;
    }

    return quadro;
};