#include <iostream>
#include <string>
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/Utils.hpp"

using namespace std;

int main() {

    string mensagem;
    int tipo_codigo;

    std::system("clear");
    cout << "Digite a mensagem que deseja transmitir: " << endl << endl;
    getline(cin, mensagem);

    printMenu();
    cin >> tipo_codigo;

    cout << tipo_codigo;

    // TODO Selecionar codificação
    CamadaFisicaTransmissora *transmissora = new CFTBinaria();
    CamadaFisicaReceptora *receptora = new CFRBinaria();
    cout << receptora->execute(transmissora->execute(stringToBinary(mensagem))) << std::endl;
    return 0;
}