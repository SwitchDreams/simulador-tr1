#ifndef SIMULACAO_HPP
#define SIMULACAO_HPP

#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/BitArray.hpp"
#include <string>
#include <iostream>

class Simulacao {
private:
    CamadaFisicaTransmissora* transmissora;
    CamadaFisicaReceptora* receptora;

public:
    Simulacao(int);
    ~Simulacao();

    /**** Transmissão ****/
    void camadaDeAplicacaoTransmissora(std::string);
    void camadaFisicaTransmissora(BitArray*);

    /**** Comunicação ****/
    void meioDeComunicacao(BitArray*);

    /**** Recepção ****/
    void camadaDeAplicacaoReceptora(BitArray*);
    void camadaFisicaReceptora(BitArray*);
};

#endif // SIMULACAO_HPP