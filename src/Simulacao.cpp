#include "../include/Simulacao.hpp"

using namespace std;

Simulacao::Simulacao(int tipo_codificacao) {
    switch(tipo_codificacao) {
        case 1:
            transmissora = new CFTManchester();
            receptora = new CFRManchester();
            break;
        case 2:
            transmissora = new CFTManchesterDiferencial();
            receptora = new CFRManchesterDiferencial();
            break;
        default:
            cout << "Tipo de codificação inválido (Utilizamos o tipo de codificação binária)" << endl;
        case 0:
            transmissora = new CFTBinaria();
            receptora = new CFRBinaria();
            break;
    }
}

Simulacao::~Simulacao() {}

/******************** Transmissão ********************/

void Simulacao::camadaDeAplicacaoTransmissora(string mensagem) {
    BitArray *quadro = new BitArray(mensagem);

    this->camadaFisicaTransmissora(quadro);
}

void Simulacao::camadaFisicaTransmissora(BitArray* quadro) {
    BitArray *fluxoBrutoDeBits = transmissora->execute(quadro);

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
    BitArray *fluxoBrutoDeBits = receptora->execute(fluxoBrutoDeBitsPontoB);

    this->camadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

void Simulacao::camadaDeAplicacaoReceptora(BitArray* fluxoBrutoDeBits) {
    string mensagem = fluxoBrutoDeBits->toString();

    cout << "A mensagem recebida foi: " << mensagem << endl;
}




