#include "../include/Simulacao.hpp"

using namespace std;

Simulacao::Simulacao(int tipoCodificacao, int tipoEnlace, int tipoErro, int chanceErro) {

    // Inicializa a camada física adequada
    switch(tipoCodificacao) {
        case 1:
            fisicaTransmissora = new CFTManchester();
            fisicaReceptora = new CFRManchester();
            break;
        case 2:
            fisicaTransmissora = new CFTManchesterDiferencial();
            fisicaReceptora = new CFRManchesterDiferencial();
            break;
        default:
            cout << "Tipo de codificação inválido (Utilizamos o tipo de codificação binária)" << endl;
        case 0:
            fisicaTransmissora = new CFTBinaria();
            fisicaReceptora = new CFRBinaria();
            break;
    }

    // Inicializa a camada de enlace adequada
    switch (tipoEnlace) {
        case 1:
            enlaceTransmissora = new CETInsercaoBytes();
            enlaceReceptora = new CERInsercaoBytes();
            break;
        case 2:
            enlaceTransmissora = new CETInsercaoBits();
            enlaceReceptora = new CERInsercaoBits();
            break;
        default:
            cout << "Tipo de codificação inválido (Utilizamos o tipo de enquadramento contagem de caracteres)" << endl;
        case 0:
            enlaceTransmissora = new CETContagemCaracteres();
            enlaceReceptora = new CERContagemCaracteres();
            break;
    }

    // Inicializa o controle de erro adequado
    switch (tipoErro) {
        case 1:
            erroTransmissora = new CTCEParidadeImpar();
            erroReceptora = new CRCEParidadeImpar();
            break;
        case 2:
            erroTransmissora = new CTCECRC();
            erroReceptora = new CRCECRC();
            break;
        case 3:
            erroTransmissora = new CTCEHamming();
            erroReceptora = new CRCEHamming();
            break;
        default:
            cout << "Tipo de controle de erro inválido (Utilizamos o bit de paridade par)" << endl;
        case 0:
            erroTransmissora = new CTCEParidadePar();
            erroReceptora = new CRCEParidadePar();
            break;
    }

    propabilidadeErro = chanceErro;
}

Simulacao::~Simulacao() {
    // delete fisicaTransmissora;
    // delete fisicaReceptora;
}

/******************** Transmissão ********************/

void Simulacao::camadaDeAplicacaoTransmissora(string mensagem) {
    BitArray *quadro = new BitArray(mensagem);

    std::cout << std::endl << "Mensagem original: ";
    quadro->print();
    std::cout << std::endl;
    
    BitArray *retornoEnquadramento = this->camadaEnlaceTransmissoraEnquadramento(quadro);
    // delete quadro;
    this->camadaFisicaTransmissora(retornoEnquadramento);
}

void Simulacao::camadaFisicaTransmissora(BitArray* quadro) {
    BitArray *fluxoBrutoDeBits = fisicaTransmissora->execute(quadro);

    // delete quadro;
    this->meioDeComunicacao(fluxoBrutoDeBits);
}

/*****************************************************/

void Simulacao::meioDeComunicacao(BitArray* fluxoBrutoDeBits) {
    // simular os bits passando de um lugar pro outro
    int tamQuadro = fluxoBrutoDeBits->tam();
    BitArray *fluxoBrutoDeBitsPontoB = new BitArray(tamQuadro * BYTE_SIZE);

    for (int i = 0; i < tamQuadro * BYTE_SIZE; i++) {
        uint8_t bit = (*fluxoBrutoDeBits)[i];

        if (rand() % 100 > propabilidadeErro) {
            bit ? fluxoBrutoDeBitsPontoB->setBit(i) : fluxoBrutoDeBitsPontoB->clearBit(i);
        } else {
            bit ? fluxoBrutoDeBitsPontoB->clearBit(i) : fluxoBrutoDeBitsPontoB->setBit(i);
        }
    }


    // delete fluxoBrutoDeBits;
    this->camadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

/********************** Recepção *********************/

void Simulacao::camadaFisicaReceptora(BitArray* fluxoBrutoDeBitsPontoB) {
    BitArray *fluxoBrutoDeBits = fisicaReceptora->execute(fluxoBrutoDeBitsPontoB);

    // delete fluxoBrutoDeBitsPontoB;
    BitArray *retornoEnquadramento = this->camadaEnlaceReceptoraEnquadramento(fluxoBrutoDeBits);

    // delete fluxoBrutoDeBits;
    this->camadaDeAplicacaoReceptora(retornoEnquadramento);
}

void Simulacao::camadaDeAplicacaoReceptora(BitArray* fluxoBrutoDeBits) {
    string mensagem = fluxoBrutoDeBits->toString();

    // delete fluxoBrutoDeBits;
    cout << "A mensagem recebida foi: " << mensagem << endl;
}

/********************** Enlace *********************/

BitArray* Simulacao::camadaEnlaceTransmissoraEnquadramento(BitArray* quadro) {
    BitArray *quadroComCodigoDeErro = erroTransmissora->execute(quadro);
    return enlaceTransmissora->execute(quadroComCodigoDeErro);
}

BitArray* Simulacao::camadaEnlaceReceptoraEnquadramento(BitArray* quadroComCodigoDeErro) {
    BitArray *quadro = enlaceReceptora->execute(quadroComCodigoDeErro) ;
    return erroReceptora->execute(quadro);
}

