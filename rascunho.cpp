#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"

void main(void) {
    AplicacaoTransmissora();
}

void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {

    CamadaFisicaTransmissora(quadro);
}

void CamadaFisicaTransmissora(int quadro[]) {
    int tipoDeCodificacao = 0;
    int fluxoBrutoDeBits[];
    switch (tipoDeCodificacao) {
        case 0:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case 1:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
            break;
        case 2:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);
            break;
    }
    MeioDeComunicacao(fluxoBrutoDeBits);
}

int[] CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]) {

}

int[] CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]) {

}

int[] CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]) {

}

void MeioDeComunicacao(int fluxoBrutoDeBits[]) {
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
        fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;
    }
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora(int quadro[]) {
    int tipoDeDecodificacao = 0;
    int fluxoBrutoDeBits[];
    switch (tipoDeDecodificacao) {
        case 0:
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
            break;
        case 1:
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(quadro);
            break;
        case 2:
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro);
            break;
    }
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

int[] CamadaFisicaReceptoraCodificacaoBinaria(int quadro[]) {

}

int[] CamadaFisicaReceptoraCodificacaoManchester(int quadro[]) {

}

int[] CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]) {

}

void CamadaDeAplicacaoReceptora(int quadro[]) {
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(string mensagem) {
    cout<< "A mensagem recebida foi:" << mensagem << endl;
}