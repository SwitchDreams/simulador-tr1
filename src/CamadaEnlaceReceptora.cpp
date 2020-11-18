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
    return quadro;
};

BitArray *CERInsercaoBits::execute(BitArray *quadro) {
    return quadro;
};