#include <iostream>
#include "../include/CamadaFisicaReceptora.hpp"

BitArray *CFRBinaria::execute(BitArray *quadro) {
    std::cout << "Decodificação Binária:";
    quadro->print();
    std::cout << std::endl;
    return quadro;
}

BitArray *CFRManchester::execute(BitArray *quadro) {
    int streamSize = quadro->tam()/2;
    u_int8_t *decodedManchesterStream = (u_int8_t *) calloc(streamSize, sizeof(u_int8_t));
    
    for (unsigned int i = 0; i < )


    return nullptr;
}

BitArray *CFRManchesterDiferencial::execute(BitArray *) {
    return nullptr;
}
