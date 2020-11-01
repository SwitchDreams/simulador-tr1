#include <iostream>
#include "../include/CamadaFisicaReceptora.hpp"

BitArray *CFRBinaria::execute(BitArray *quadro) {
    std::cout << "Decodificação Binária:";
    quadro->print();
    std::cout << std::endl;
    return quadro;
}

BitArray *CFRManchester::execute(BitArray *quadro) {
    int streamSize = BYTE_SIZE*quadro->tam()/2;
    
    BitArray* decodedArray = new BitArray(streamSize);

    for (unsigned int i = 0; i < streamSize; i++) {
        if((*quadro)[i*2] == 0 && (*quadro)[i*2 + 1] == 1) {
            decodedArray->clearBit(i);
        } else if ((*quadro)[i*2] == 1 && (*quadro)[i*2 + 1] == 0) {
            decodedArray->setBit(i);
        } else {
            std::cout << "Erro!" << std::endl;
        }
    }

    std::cout << "Decodificação Manchester:";
    decodedArray->print();
    std::cout << std::endl;

    return decodedArray;
}

BitArray *CFRManchesterDiferencial::execute(BitArray *) {
    return nullptr;
}
