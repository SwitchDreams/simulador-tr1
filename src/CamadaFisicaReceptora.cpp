#include <cstdint>
#include <iostream>
#include "../include/CamadaFisicaReceptora.hpp"

uint8_t *CFRBinaria::execute(uint8_t *quadro) {
    std::cout << "Decodificação Binária:";
    printBinaryArray(quadro);
    std::cout << std::endl;
    return quadro;
}

uint8_t *CFRManchester::execute(uint8_t *) {
    return nullptr;
}

uint8_t *CFRManchesterDiferencial::execute(uint8_t *) {
    return nullptr;
}
