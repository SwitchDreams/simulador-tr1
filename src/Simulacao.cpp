#include "../include/Simulacao.hpp"

using namespace std;

Simulacao::Simulacao(int tipoCodificacao, int tipoEnlace) {

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
            cout << "Tipo de codificação inválido (Utilizamos o tipo de codificação binária)" << endl;
        case 0:
            enlaceTransmissora = new CETContagemCaracteres();
            enlaceReceptora = new CERContagemCaracteres();
            break;
    }
}

Simulacao::~Simulacao() {
    delete fisicaTransmissora;
    delete fisicaReceptora;
}

/******************** Transmissão ********************/

void Simulacao::camadaDeAplicacaoTransmissora(string mensagem) {
    BitArray *quadro = new BitArray(mensagem);

    std::cout << std::endl << "Mensagem original: ";
    quadro->print();
    std::cout << std::endl;
    
    BitArray *retornoEnquadramento = this->camadaEnlaceTransmissoraEnquadramento(quadro);
    this->camadaFisicaTransmissora(retornoEnquadramento);
}

void Simulacao::camadaFisicaTransmissora(BitArray* quadro) {
    BitArray *fluxoBrutoDeBits = fisicaTransmissora->execute(quadro);

    this->meioDeComunicacao(fluxoBrutoDeBits);
}

/*****************************************************/

void Simulacao::meioDeComunicacao(BitArray* fluxoBrutoDeBits) {
    // simular os bits passando de um lugar pro outro

    BitArray *fluxoBrutoDeBitsPontoB = fluxoBrutoDeBits;

    this->camadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

/********************** Recepção *********************/

void Simulacao::camadaFisicaReceptora(BitArray* fluxoBrutoDeBitsPontoB) {
    BitArray *fluxoBrutoDeBits = fisicaReceptora->execute(fluxoBrutoDeBitsPontoB);

    BitArray *retornoEnquadramento = this->camadaEnlaceReceptoraEnquadramento(fluxoBrutoDeBits);
    this->camadaDeAplicacaoReceptora(retornoEnquadramento);
}

void Simulacao::camadaDeAplicacaoReceptora(BitArray* fluxoBrutoDeBits) {
    string mensagem = fluxoBrutoDeBits->toString();

    cout << "A mensagem recebida foi: " << mensagem << endl;
}

/********************** Enlace *********************/

BitArray* Simulacao::camadaEnlaceTransmissoraEnquadramento(BitArray* quadro) {
    return enlaceTransmissora->execute(quadro);
}

BitArray* Simulacao::camadaEnlaceReceptoraEnquadramento(BitArray* quadro) {
    return enlaceReceptora->execute(quadro);
}

