#include "../include/CamadaFisicaTransmissora.hpp"

BitArray *CFTBinaria::execute(BitArray *quadro) {
    std::cout << "Codificação Binária: ";
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
            bitArray->setBit(i*2 + 1);
        }
    }

    std::cout << "Codificação Manchester: ";
    bitArray->print();
    std::cout << std::endl;

    return bitArray;
}

BitArray *CFTManchesterDiferencial::execute(BitArray *quadro) {
    int streamSize = 2*quadro->tam()*BYTE_SIZE;

    std::cout << "TÁ DESSE JEITO AQUI: ";
    quadro->print();
    std::cout << std::endl;
    BitArray* bitArray = new BitArray(streamSize);
    int lastState;

    if ((*quadro)[0]) {
        bitArray->setBit(0);  // 0*2 
        bitArray->clearBit(1);  // 0*2 + 1

        lastState = 0;
    } else {
        bitArray->clearBit(0);  // 0*2
        bitArray->setBit(1);  // 0*2 + 1

        lastState = 1;
    }

    for (unsigned int i = 1; i < streamSize/2; i++) {

        if ((*quadro)[i]) {
            // Se o bit é 1, não há transição de estado
            if (lastState) {
                // Se terminou em 1, continua 1
                bitArray->setBit(i*2);
                bitArray->clearBit(i*2 + 1);

                lastState = 0;
            } else {
                // Se terminou em 0, continua 0
                bitArray->clearBit(i*2);
                bitArray->setBit(i*2 + 1);

                lastState = 1;
            }
        } else {
            // Se o bit é 0, deve haver transição de estado
            if (lastState) {
                // Se terminou em 1, vai para 0
                bitArray->clearBit(i*2);
                bitArray->setBit(i*2 + 1);

                lastState = 1;
            } else {
                // Se terminou em 0, vai para 1
                bitArray->setBit(i*2);
                bitArray->clearBit(i*2 + 1);

                lastState = 0;
            }
        }
    }

    std::cout << "Codificação Manchester Diferencial: ";
    bitArray->print();
    std::cout << std::endl;

    return bitArray;
}
