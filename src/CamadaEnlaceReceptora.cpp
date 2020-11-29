#include <iostream>
#include "../include/CamadaEnlaceReceptora.hpp"
#include "../include/Utils.hpp"

BitArray *CERContagemCaracteres::execute(BitArray *quadro) {
    std::cout << "Decodificação Contagem de Caracteres: ";

    // Tamanho do quadro em BYTES
    int tamanhoQuadro = (int) quadro->tam();

    std::string mensagem;
    // Pega a mensagem pulando o cabeçalho
    for (int i = 1; i < tamanhoQuadro; i += 2) {
        // Começa do segundo byte porconta do cabeçalho
        mensagem += quadro->getByte(i);
    }

    // Cria um novo quadro sem o cabeçalho
    auto *quadroSemCabecalho = new BitArray(mensagem);

    quadroSemCabecalho->print();
    std::cout << std::endl;
    return quadroSemCabecalho;
};

BitArray *CERInsercaoBytes::execute(BitArray *quadro) {

    uint8_t byte = 0, previousByte, indice = 0;
    int lastEscIsData = 0, anterior = 0;
    std::string mensagem;

    for(unsigned int i = 0; i < quadro->tam(); i++) {

        previousByte = byte; // Salvando o byte anterior para verificações

        byte = quadro->getByte(i);

        anterior = i-1;

        // Verificando se deve-se descartar a informação
        if(byte == BYTE_FLAG and previousByte != BYTE_ESC) {
            // O valor é uma flag, pois o anterior não é o byte de escape
            continue;
        } else if (byte == BYTE_ESC and previousByte != BYTE_ESC) {
            // O valor não é do campo de carga útil
            // É um escape, pois o anterior não é o byte de escape
            continue;
        } else if (byte == BYTE_ESC and previousByte == BYTE_ESC and lastEscIsData != anterior) {
            // O esc anterior não é de dado
            lastEscIsData = i; // Atual é de dado
        } else if ((byte == BYTE_FLAG or byte == BYTE_ESC) and previousByte == BYTE_ESC and lastEscIsData == anterior) {
            // Esc anterior é de dados, atual é esc normal
            continue;
        }

        mensagem += quadro->getByte(i);
    }

    BitArray* quadroDecodificado = new BitArray(mensagem);

    std::cout << "Decodificação da Inserção de Byte: ";
    quadroDecodificado->print();
    std::cout << std::endl;

    return quadroDecodificado;
};

BitArray *CERInsercaoBits::execute(BitArray *quadro) {

    // Se o quadro for múltiplo de 3, não houve inserção de bits
    if (quadro->tam() % 3 == 0) {
        std::string mensagem = "";
        for (unsigned int i = 0; i < quadro->tam(); i ++) {
            uint8_t byte = quadro->getByte(i);

            // Se o byte não for a flag, insere na mensagem final
            if (byte != BIT_FLAG) {
                mensagem.push_back(byte);
            }
        }

        BitArray* bitArray = new BitArray(mensagem);
        return bitArray;
    } else {
        std::vector<uint8_t> bitsDaMensagem, bitsSemFlag;
        // Insere bitArray em um vector para facilitar a manipulação
        for(unsigned int i = 0; i < quadro->tam() * BYTE_SIZE; i++) {
            bitsDaMensagem.push_back((*quadro)[i]);
        }

        int numBits = 0;
        bool fiveBits = false;
        uint8_t byte = 0;
        std::vector<uint8_t> aux;
        for (unsigned int i = 0; i < bitsDaMensagem.size(); i++) {
            uint8_t bit = bitsDaMensagem[i];
            //conta os bits
            bit ? numBits++ : numBits = 0;
            aux.push_back(bit);

            // Se temos 5 bits 1 seguidos, seta a flag como true
            if (numBits == 5) {
                fiveBits = true;
                continue;
            }

            // Se tivermos 5 bits 1
            if (fiveBits) {
                fiveBits = false;
                if (numBits == 6) {
                    // Se tivermos 6 bits 1, é FLAG
                    // Retiramos os ultimos 7 elementos, pulamos o próximo (i++)
                    // e saímos do loop (continue)
                    aux.resize(aux.size() - 7);
                    i++;
                    continue;
                } else {
                    aux.pop_back();
                    numBits = 0;
                }
            }
        }

        aux.resize(aux.size() - 7);

        // Converte em bitArray
        std::string mensagem = "";
        for (unsigned int i = 0; i < aux.size(); i += BYTE_SIZE) {
            uint8_t byte = 0;
            for (unsigned int j = 0; j < BYTE_SIZE; j++) {
                byte |= aux[i + j] << j;
            }
            mensagem.push_back(byte);
        }

        return new BitArray(mensagem);
    }

    return quadro;
};