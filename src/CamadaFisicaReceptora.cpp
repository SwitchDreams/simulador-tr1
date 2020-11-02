#include <iostream>
#include "../include/CamadaFisicaReceptora.hpp"

BitArray *CFRBinaria::execute(BitArray *quadro) {
    std::cout << "Decodificação Binária: ";
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

    std::cout << "Decodificação Manchester: ";
    decodedArray->print();
    std::cout << std::endl;

    return decodedArray;
}

BitArray *CFRManchesterDiferencial::execute(BitArray *quadro) {
    int streamSize = BYTE_SIZE*quadro->tam()/2;
    
    BitArray* decodedArray = new BitArray(streamSize);
    int currBit, lastBit;

    if ((*quadro)[0] == 1 and (*quadro)[1] == 0) {
        // Se é uma borda de descida, o bit == 1
        decodedArray->setBit(0);
        lastBit = 0;
    } else if ((*quadro)[0] == 0 and (*quadro)[1] == 1) {
        // Se é uma borda de subida, o bit == 0
        decodedArray->clearBit(0);
        lastBit = 1;
    } else {
        std::cout << "Erro!" << std::endl;
    }

    for (unsigned int i = 1; i < streamSize; i++) {
        currBit = (*quadro)[i*2];

        if (currBit xor lastBit) {
            // Se xor == 1, houve mudança de estado
            // logo bit = 0
            decodedArray->clearBit(i);
        } else {
            // Se xor == 0, não houve mudança de estado
            // logo bit = 1
            decodedArray->setBit(i);
        }

        lastBit = (*quadro)[i*2 + 1];
    }

    std::cout << "Decodificação Manchester Diferencial: ";
    decodedArray->print();
    std::cout << std::endl;
    
    return decodedArray;
}
