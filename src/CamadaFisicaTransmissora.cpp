#include "../include/CamadaFisicaTransmissora.hpp"

BitArray *CFTBinaria::execute(BitArray *quadro) {
    std::cout << "Codificação Binária:";
    quadro->print();
    std::cout << std::endl;
    return quadro;
}

BitArray *CFTManchester::execute(BitArray *) {
    return nullptr;
}

BitArray *CFTManchesterDiferencial::execute(BitArray *) {
    return nullptr;
}
