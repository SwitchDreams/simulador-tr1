#include <iostream>
#include <string>
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/Utils.hpp"
#include "../include/BitArray.hpp"

using namespace std;


void meioDeComunicacao(BitArray* fluxoBrutoDeBits) {
    BitArray* fluxoBrutoDeBitsPontoA, *fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
        fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;
    }
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void camadaFisicaTransmissora(BitArray ba, int tipoDeCodificacao) {
    BitArray* fluxoBrutoDeBits;
    CamadaFisicaTransmissora *transmissora;
    switch (tipoDeCodificacao) {
        case 1:
            transmissora = new CFTManchester();
            break;
        case 2:
            transmissora = new CFTManchesterDiferencial();
            break;
        default:
            cout << "Tipo de codificação inválido (Utilizamos o tipo de codificação binária)" << endl;
        case 0:
            transmissora = new CFTBinaria();
            break;
    }
    fluxoBrutoDeBits = transmissora->execute(&ba);
    meioDeComunicacao(fluxoBrutoDeBits);
}

void camadaDeAplicacaoTransmissora(string mensagem) {
    BitArray ba = BitArray(mensagem);
    camadaFisicaTransmissora(ba);
}


int main() {

    string mensagem;
    int tipo_codigo;

    std::system("clear");
    cout << "Digite a mensagem que deseja transmitir: " << endl << endl;
    getline(cin, mensagem);

    tipo_codigo = printMenu();

    // TODO Selecionar codificação

    CamadaFisicaReceptora *receptora = new CFRBinaria();
    receptora->execute(transmissora->execute(&ba));
    return 0;
}
