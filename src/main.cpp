#include <iostream>
#include <string>
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/Utils.hpp"

using namespace std;

int main() {
    string mensagem;
    cout << "Digite a sua mensagem" << endl;
    cin >> mensagem;
    // TODO Selecionar codificação
    CamadaFisicaTransmissora *transmissora = new CFTBinaria();
    CamadaFisicaReceptora *receptora = new CFRBinaria();
    cout << receptora->execute(transmissora->execute(stringToBinary(mensagem))) << std::endl;
    return 0;
}