#include "../include/CamadaReceptoraControleDeErro.hpp"

BitArray *CRCEParidade::execute(BitArray* quadro, bool isPar) {
    auto quadroSemBitDeParidade = new BitArray(quadro->tam() - 1);
    // quadroComBitDeParidade = quadro;
    const bool quantidadeBitsOnePar = quadro->contBitsOne() % 2 == 0;
    if (quantidadeBitsOnePar && !isPar) {
        std::cout << "Bit de paridade errado" << std::endl;
    }
    return quadroSemBitDeParidade;
}

BitArray *CRCEParidadePar::execute(BitArray* quadro) {
    return CRCEParidade::execute(quadro, true);
}

BitArray *CRCEParidadeImpar::execute(BitArray* quadro) {
    return CRCEParidade::execute(quadro, false);
}

BitArray *CRCECRC::execute(BitArray* quadro) {
    return quadro;
}

BitArray *CRCEHamming::execute(BitArray* quadro) {
    return quadro;
}

