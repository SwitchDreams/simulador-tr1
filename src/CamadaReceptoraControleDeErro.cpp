#include "../include/CamadaReceptoraControleDeErro.hpp"
#include "../include/Utils.hpp"
#include <cmath>

BitArray *CRCEParidade::execute(BitArray *quadro, bool isPar) {
    auto quadroSemBitDeParidade = new BitArray((quadro->tam() - 1) * BYTE_SIZE);
    quadroSemBitDeParidade->copyBits(quadro);
    const bool quantidadeBitsOnePar = quadro->contBitsOne() % 2 == 0;
    if (quantidadeBitsOnePar && !isPar) {
        std::cout << "Bit de paridade errado" << std::endl;
    } else {
        std::cout << "Bit de paridade correto" << std::endl;
    }
    std::cout << "Retirada de bit de paridade:";
    quadroSemBitDeParidade->print();
    std::cout << std::endl;

    return quadroSemBitDeParidade;
}

BitArray *CRCEParidadePar::execute(BitArray *quadro) {
    return CRCEParidade::execute(quadro, true);
}

BitArray *CRCEParidadeImpar::execute(BitArray *quadro) {
    return CRCEParidade::execute(quadro, false);
}

BitArray *CRCECRC::execute(BitArray *quadro) {
    return quadro;
}

BitArray *CRCEHamming::execute(BitArray *quadro) {
    unsigned int tamBits = quadro->tam() * BYTE_SIZE;
    int correctSum = 0;
    int redundantBits = 0;
    for (unsigned int i = 0; i < tamBits; i++) {
        // Caso não seja redundante continua
        if (!isPow2(i + 1))
            continue;

        redundantBits++;
        int x = (int) log2(i + 1);
        int one_count = 0;

        for (int j = i + 2;
             j <= (tamBits); ++j) {

            if (j & (1 << x)) {
                if ((*quadro)[j - 1]) {
                    one_count++;
                }
            }
        }

        one_count += (*quadro)[i];
        // Caso seja impar
        if (one_count % 2 == 1) {
            correctSum += (int) pow(2, i);
        }
    }

    if (correctSum != 0) {
        std::cout << "Recebido antes de corrigir: ";
        quadro->print();
        std::cout << std::endl;

        int correctIndex = correctSum - 1;
        std::cout << "Aconteceu erro na transmissão, na posição: " << correctIndex << std::endl;
        std::cout << "Caso tenha ocorrido erro em mais de um bit, essa posição pode estar equivocada." << std::endl;
        // Correção do erro
        (*quadro)[correctIndex] ? quadro->clearBit(correctIndex) : quadro->setBit(correctIndex);

        std::cout << "Corrigido: ";
        quadro->print();
        std::cout << std::endl;
    } else {
        std::cout << "Sucesso na transmissão" << std::endl;
    }

    auto quadroSemHamming = new BitArray((quadro->tam() - 1) * BYTE_SIZE - redundantBits);

    for (unsigned int i = 0, j = 0; i < tamBits; i++) {
        if (isPow2(i + 1))
            continue;
        if ((*quadro)[i]) {
            quadroSemHamming->setBit(j);
        } else {
            quadroSemHamming->clearBit(j);
        }
        j++;
    }

    std::cout << "Decodificação Hamming: ";
    quadroSemHamming->print();
    std::cout << std::endl;
    return quadroSemHamming;
}

