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

    std::vector<int> originalCRC, restoCRC;
    int tam = quadro->tam() - 4;
    for (int i = tam*BYTE_SIZE; i < quadro->tam()*BYTE_SIZE; i++) {
        originalCRC.push_back((*quadro)[i]);
    }
    // Remove o zero extra adicionado pelo construtor da bitarray
    originalCRC.pop_back();

    uint32_t resto = 0xFFFFFFFF, crcOriginal = 0;
    for (int i = 0; i < quadro->tam() - 4; i++) {
        uint32_t byte = quadro->getByte(i);

        for (int j = 0; j < BYTE_SIZE; j++) {
            uint32_t bit = (byte xor resto)&1;
            resto >>= 1;

            if (bit) {
                resto = resto xor CRC_POLYNOMIAL;
            }
            byte >>=1;
        }
    }

    resto ^= 0xFFFFFFFF;

    int cont = 1;
    for (int bit : originalCRC) {
        crcOriginal += pow(2, cont) * bit;
        cont++;
    }

    if (resto != crcOriginal) {
        std::cout << "Erro na transmissão da mensagem. Os CRCs não batem." << std::endl << sdt::endl;
    }

    BitArray* mensagem = new BitArray((quadro->tam() - 4) * BYTE_SIZE);
    for (int i = 0; i < (quadro->tam() - 4) * BYTE_SIZE; i++) {
        uint8_t bit = (*quadro)[i];

        bit ? mensagem->setBit(i) : mensagem->clearBit(i);
    }

    return mensagem;
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

