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
    int tipo_codigo, tipo_enquadramento;

    // Recebe a mensagem do usuário
    std::system("clear");
    cout << "Digite a mensagem que deseja transmitir: " << endl << endl;
    getline(cin, mensagem);

    // Recebe a codificação a ser utilizada
    tipo_codigo = getMenuCodigo();
    tipo_enquadramento = getMenuEnquadramento();

    // Instancia uma nova simulação
    Simulacao *simulacao = new Simulacao(tipo_codigo);

    simulacao->camadaDeAplicacaoTransmissora(mensagem);

    delete simulacao;
    return 0;
}
