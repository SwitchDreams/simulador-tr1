#include <cstdint>
#include "../include/CamadaFisicaTransmissora.hpp"

uint8_t *CFTBinaria::execute(uint8_t *quadro) {
    std::cout << "Codificação Binária:";
    printBinaryArray(quadro);
    std::cout << std::endl;
    return quadro;
}

uint8_t *CFTManchester::execute(uint8_t *) {
    return nullptr;
}

uint8_t *CFTManchesterDiferencial::execute(uint8_t *) {
    return nullptr;
}
