#include <iostream>
#include <string>
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/Utils.hpp"
#include "../include/BitArray.hpp"

using namespace std;

int main() {

    string mensagem;
    int tipo_codigo;

    std::system("clear");
    cout << "Digite a mensagem que deseja transmitir: " << endl << endl;
    getline(cin, mensagem);

    tipo_codigo = printMenu();

    // TODO Selecionar codificação
    CamadaFisicaTransmissora *transmissora = new CFTBinaria();
    CamadaFisicaReceptora *receptora = new CFRBinaria();

    BitArray *ba = new BitArray(mensagem);

    ba->print();

    // cout << receptora->execute(transmissora->execute(stringToBinary(mensagem))) << std::endl;
    return 0;
}