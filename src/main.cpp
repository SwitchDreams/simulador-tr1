#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaFisicaTransmissora.hpp"
#include <iostream>
#include <string>

#define BITSIZE 8

void  SetBit( uint8_t A[],  int k )
{
    A[k/BITSIZE] |= 1 << (k%BITSIZE);  // Set the bit at the k-th position in A[i]
}

void  ClearBit( uint8_t A[],  int k )
{
    A[k/BITSIZE] &= ~(1 << (k%BITSIZE));
}

int GetBit( uint8_t A[],  int k )
{
    return ( (A[k/BITSIZE] & (1 << (k%BITSIZE) )) != 0 ) ;
}


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
    // ClearBit(msg, 0);
    ClearBit(msg, 0);
    SetBit(msg, 15);
    cout << GetBit(msg, 0);
    cout << GetBit(msg, 1);
    cout << GetBit(msg, 2);
    cout << GetBit(msg, 3);
    cout << GetBit(msg, 4);
    cout << GetBit(msg, 5);
    cout << GetBit(msg, 6);
    cout << GetBit(msg, 7);
    cout<<"  ";
    cout << GetBit(msg, 8);
    cout << GetBit(msg, 9);
    cout << GetBit(msg, 10);
    cout << GetBit(msg, 11);
    cout << GetBit(msg, 12);
    cout << GetBit(msg, 13);
    cout << GetBit(msg, 14);
    cout << GetBit(msg, 15);



    return 0;
}