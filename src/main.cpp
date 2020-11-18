#include <iostream>
#include <string>
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/Utils.hpp"
#include "../include/BitArray.hpp"
#include "../include/Simulacao.hpp"

using namespace std;

int main() {

    string mensagem;
    int tipoCodigo, tipoEnquadramento;

    // Recebe a mensagem do usuário
    std::system("clear");
    cout << "Digite a mensagem que deseja transmitir: " << endl << endl;
    getline(cin, mensagem);

    // Recebe a codificação a ser utilizada
    tipoCodigo = getMenuCodigo();
    tipoEnquadramento = getMenuEnquadramento();

    // Instancia uma nova simulação
    Simulacao *simulacao = new Simulacao(tipoCodigo, tipoEnquadramento);

    simulacao->camadaDeAplicacaoTransmissora(mensagem);

    delete simulacao;
    return 0;
}
