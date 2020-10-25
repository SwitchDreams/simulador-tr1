#include "../include/Simulacao.hpp"

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
            std::cout << "Tipo de codificação inválido (Utilizamos o tipo de codificação binária)" << std::endl;
        case 0:
            transmissora = new CFTBinaria();
            receptora = new CFRBinaria();
            break;
    }
}

Simulacao::~Simulacao() {

}

/******************** Transmissão ********************/

void Simulacao::camadaDeAplicacaoTransmissora(std::string mensagem) {}

void Simulacao::camadaFisicaTransmissora() {}

/*****************************************************/

/********************** Recepção *********************/

void Simulacao::camadaDeAplicacaoReceptora() {}

void Simulacao::camadaFisicaReceptora() {}

/*****************************************************/

void Simulacao::meioDeComunicacao() {}


