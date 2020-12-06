#include "../include/CamadaTransmissoraControleDeErro.hpp"

BitArray *CTCEParidade::execute(BitArray *quadro, bool isPar) {
    // Caso a quantidade de bits 1 seja par
    auto quadroComBitDeParidade = new BitArray((quadro->tam() + 1) * BYTE_SIZE);
    quadroComBitDeParidade->copyBits(quadro);
    const unsigned lastBit = quadro->tam() * BYTE_SIZE + 1;
    if (quadro->contBitsOne() % 2 == 0) {
        if (isPar) {
            quadroComBitDeParidade->clearBit(lastBit);
        } else {
            quadroComBitDeParidade->setBit(lastBit);
        }
    } else {
        if (isPar) {
            quadroComBitDeParidade->setBit(lastBit);
        } else {
            quadroComBitDeParidade->clearBit(lastBit);
        }
    }

    std::cout << "Adição de bit de paridade:";
    quadroComBitDeParidade->print();
    return quadroComBitDeParidade;
}

BitArray *CTCEParidadePar::execute(BitArray *quadro) {
    return CTCEParidade::execute(quadro, true);
}

BitArray *CTCEParidadeImpar::execute(BitArray *quadro) {
    return CTCEParidade::execute(quadro, false);
}

BitArray *CTCECRC::execute(BitArray *quadro) {
    return quadro;
}

BitArray *CTCEHamming::execute(BitArray *quadro) {
    return quadro;
}
