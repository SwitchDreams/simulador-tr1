#include "../include/CamadaFisicaTransmissora.hpp"

BitArray *CFTBinaria::execute(BitArray *quadro) {
    std::cout << "Codificação Binária:";
    quadro->print();
    std::cout << std::endl;
    return quadro;
}

BitArray *CFTManchester::execute(BitArray *quadro) {
    int streamSize = 2*quadro->tam()*BYTE_SIZE;
    
    BitArray* bitArray = new BitArray(streamSize);

    for (unsigned int i = 0; i < streamSize/2 ; i++) {
        if ((*quadro)[i]) {
            //bitArray->setBit(i); // Copia informação do quadro 
            // Se o bit == 1, borda de caída 1->0
            bitArray->setBit(i*2);
            bitArray->clearBit(i*2 + 1);
        } else {
            //bitArray->clearBit(i); // Copia informação do quadro 
            // Se o bit == 0, borda de subida 0->1
            bitArray->clearBit(i*2);
            bitArray->clearBit(i*2 + 1);
        }
    }

    std::cout << "Codificação Manchester:";
    bitArray->print();
    std::cout << std::endl;

    return bitArray;
}

BitArray *CFTManchesterDiferencial::execute(BitArray *quadro) {
    return nullptr;
}
