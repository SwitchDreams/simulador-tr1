#include <iostream>
#include "../include/CamadaFisicaReceptora.hpp"

BitArray *CFRBinaria::execute(BitArray *quadro) {
    std::cout << "Decodificação Binária:";
    quadro->print();
    std::cout << std::endl;
    return quadro;
}

BitArray *CFRManchester::execute(BitArray *) {
    return nullptr;
}

BitArray *CFRManchesterDiferencial::execute(BitArray *) {
    return nullptr;
}
