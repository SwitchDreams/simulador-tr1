#include "../include/CamadaTransmissoraControleDeErro.hpp"
#include <cmath>
#include "../include/Utils.hpp"
BitArray *CTCEParidade::execute(BitArray *quadro, bool isPar) {
    // Caso a quantidade de bits 1 seja par
    auto quadroComBitDeParidade = new BitArray((quadro->tam() + 1) * BYTE_SIZE);
    quadroComBitDeParidade->copyBits(quadro);
    const unsigned lastBit = quadro->tam() * BYTE_SIZE;
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
    std::cout << std::endl;
    return quadroComBitDeParidade;
}

BitArray *CTCEParidadePar::execute(BitArray *quadro) {
    return CTCEParidade::execute(quadro, true);
}

BitArray *CTCEParidadeImpar::execute(BitArray *quadro) {
    return CTCEParidade::execute(quadro, false);
}

BitArray *CTCECRC::execute(BitArray *quadro) {

    std::vector<int> quadroComCRC, restoCRC;
    for (int i = 0; i < quadro->tam() * BYTE_SIZE; i++) {
        quadroComCRC.push_back((*quadro)[i]);
    }

    uint32_t resto = 0xFFFFFFFF;
    for (int i = 0; i < quadro->tam(); i++) {
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
    
    for (int i = 1; i < CRC_SIZE; i++) {
        restoCRC.push_back((resto & ( 1 << i )) >> i);
    }

    quadroComCRC.insert(quadroComCRC.end(), restoCRC.begin(), restoCRC.end());

    BitArray* bitArrayCRC = new BitArray(quadroComCRC.size());
    for (int i = 0; i < quadroComCRC.size(); i++) {
        quadroComCRC[i] ? bitArrayCRC->setBit(i) : bitArrayCRC->clearBit(i);
    }

    std::cout << "Polinômio CRC utilizado: " << CRC_POLYNOMIAL << " (11101101101110001000001100100000)" << std::endl;
    std::cout << "Resto da divisão: ";
    for (auto bit : restoCRC) {
        std::cout << bit;
    }
    std::cout << std::endl;
    std::cout << "Quadro completo: ";
    bitArrayCRC->print();
    std::cout << std::endl;

    return bitArrayCRC;
}


BitArray *CTCEHamming::execute(BitArray *quadro) {

    // Tamanho da mensagem em bits
    unsigned int tamBits = quadro->tam() * 8;

    // Número de bits redudantes
    int r = 1;

    // Find no. of redundant bits
    while (pow(r, 2) < (tamBits + r + 1)) {
        r++;
    }

    // HammingCode
    auto palavraDeCodigo = new BitArray(tamBits + r);

    // Copia dados no lugar corrto
    for (unsigned int i = 0, j = 0; i < (tamBits + r); i++) {
        // Caso seja bit de redudancia
        if (isPow2(i + 1)) {
            // Zera o bit
            palavraDeCodigo->clearBit(i);
        } else {
            // Caso ja bit de dado preenche o dado
            if ((*quadro)[j]) {
                palavraDeCodigo->setBit(i);
            } else {
                palavraDeCodigo->clearBit(i);
            }
            j++;
        }
    }

    for (unsigned int i = 0; i < (tamBits + r); i++) {
        // Caso não seja redundante continua
        if (!isPow2(i + 1))
            continue;

        int x = (int) log2(i + 1);
        int one_count = 0;

        for (int j = i + 2;
             j <= (r + tamBits); ++j) {

            if (j & (1 << x)) {
                if ((*palavraDeCodigo)[j - 1]) {
                    one_count++;
                }
            }
        }

        // Generating hamming code for
        // even parity
        if (one_count % 2 == 0) {
            palavraDeCodigo->clearBit(i);
        } else {
            palavraDeCodigo->setBit(i);
        }
    }

    std::cout << "A leitura deve ser feita levando em consideração que estão em formato MSB para facilitar a compreensão do algoritmo" << std::endl;
    std::cout << "Palavra de código (Hamming Code): ";
    palavraDeCodigo->printMSB();
    std::cout << std::endl;
    return palavraDeCodigo;
}