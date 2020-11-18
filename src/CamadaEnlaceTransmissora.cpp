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
    return quadro;
};

BitArray *CETInsercaoBits::execute(BitArray *quadro) {
    return quadro;
};