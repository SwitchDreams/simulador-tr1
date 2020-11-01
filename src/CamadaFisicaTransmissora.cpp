#include "../include/CamadaFisicaTransmissora.hpp"

BitArray *CFTBinaria::execute(BitArray *quadro) {
    std::cout << "Codificação Binária:";
    quadro->print();
    std::cout << std::endl;
    return quadro;
}

BitArray *CFTManchester::execute(BitArray *quadro) {
    int streamSize = 2*quadro->tam()*BYTE_SIZE;
    u_int8_t *manchesterStream = (u_int8_t *) calloc(streamSize, sizeof(u_int8_t));

    for (unsigned int i = 0; i < quadro->tam() * BYTE_SIZE; i++) {
        u_int8_t bit = (*quadro)[i];
        if (bit) {
            // Se o bit == 1, borda de caída 1->0
            manchesterStream[i*2]     = 1;
            manchesterStream[i*2 + 1] = 0;
        } else {
            // Se o bit == 0, borda de subida 0->1
            manchesterStream[i*2]     = 0;
            manchesterStream[i*2 + 1] = 1;
        }
    }
    return new BitArray(manchesterStream, streamSize);
}

BitArray *CFTManchesterDiferencial::execute(BitArray *quadro) {
    return nullptr;
}
