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
    return quadro;
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

    std::cout << "Primeira parte: ";
    for (unsigned int i = 0; i < palavraDeCodigo->tam() * BYTE_SIZE; i++) {
        std::cout << (*palavraDeCodigo)[i]; // Printa o bit no terminal
    }
    //palavraDeCodigo->print();
    std::cout << std::endl;

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

    std::cout << "Palavra de código (Hamming Code): ";
    //palavraDeCodigo->print();
    for (unsigned int i = 0; i < palavraDeCodigo->tam() * BYTE_SIZE; i++) {
        std::cout << (*palavraDeCodigo)[i]; // Printa o bit no terminal
    }
    std::cout << std::endl;
    return palavraDeCodigo;
}