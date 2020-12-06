#include "../include/CamadaTransmissoraControleDeErro.hpp"
#include <cmath>

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

bool isPow2(unsigned int v) {
    return v && !(v & (v - 1));
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

    int coversBits; // Covers 2^îndex bi    ts
    int contBits; // Conta quantos bits foram pulados ou colocados
    int contOnes; // Conta a quantidade de uns
    bool jmp; // Varíavel que guarda a informação se é para pular ou prencher o bit
    // Para cada bit rendundante
    for (unsigned int i = 0; i < r; i++) {
        coversBits = (int) pow(2, i);
        contBits = 0;
        contOnes = 0;
        jmp = true;
        for (unsigned int j = 0; j < tamBits; j++) {
            if (contBits == coversBits) {
                contBits = 0; // Reseta o contador de bits
                jmp = !jmp;// Toogle jmp
            }
            // Caso o bit seja 1 e não é para pular
            if (!jmp and (*palavraDeCodigo)[j]) {
                contOnes++;
            }
            contBits++;
        }

        if (contOnes % 2 == 0) {
            palavraDeCodigo->clearBit((int) pow(2, i) - 1);
        } else {
            palavraDeCodigo->setBit((int) pow(2, i) - 1);
        }
    }

    std::cout << "Palavra de código (Hamming Code): ";
    palavraDeCodigo->print();
    /*for (unsigned int i = 0; i < palavraDeCodigo->tam() * BYTE_SIZE; i++) {
        std::cout << (*palavraDeCodigo)[i]; // Printa o bit no terminal
    }*/
    std::cout << std::endl;
    return palavraDeCodigo;
}


// 10010110

// PPDPDDDP DDDDDDDDDD
// 00100010 0110