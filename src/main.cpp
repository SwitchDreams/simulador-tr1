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
    int tipo_codigo;

    // Recebe a mensagem do usuário
    std::system("clear");
    cout << "Digite a mensagem que deseja transmitir: " << endl << endl;
    getline(cin, mensagem);

    // Recebe a codificação a ser utilizada
    tipo_codigo = printMenu();

    // Instancia uma nova simulação
    Simulacao *simulacao = new Simulacao(tipo_codigo);

    simulacao->camadaDeAplicacaoTransmissora(mensagem);

    return 0;
}

// TODO fazer separadamente a Aplicação Transmissora/Receptora ou deixar como está
// TODO dar free em todos os callocs