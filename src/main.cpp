#include <iostream>
#include <string>
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/Utils.hpp"

using namespace std;

int main() {
    string mensagem;
    uint8_t *msg;
    cout << "Digite a sua mensagem" << endl;
    cin >> mensagem;

    msg = (uint8_t *) malloc(mensagem.length() * sizeof(uint8_t));

    CamadaFisicaTransmissora *transmissora = new CFTBinaria();

    int contador = 0;
    for (char letra : mensagem) {
        msg[contador] = letra;
        contador++;
    } // 0100 0001 0100 0001
    // transmissora->execute();
    // clearBit(msg, 0);
    clearBit(msg, 0);
    setBit(msg, 15);
    cout << getBit(msg, 0);
    cout << getBit(msg, 1);
    cout << getBit(msg, 2);
    cout << getBit(msg, 3);
    cout << getBit(msg, 4);
    cout << getBit(msg, 5);
    cout << getBit(msg, 6);
    cout << getBit(msg, 7);
    cout<<"  ";
    cout << getBit(msg, 8);
    cout << getBit(msg, 9);
    cout << getBit(msg, 10);
    cout << getBit(msg, 11);
    cout << getBit(msg, 12);
    cout << getBit(msg, 13);
    cout << getBit(msg, 14);
    cout << getBit(msg, 15);



    return 0;
}