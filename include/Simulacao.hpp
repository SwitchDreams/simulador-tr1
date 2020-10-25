#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/BitArray.hpp"
#include <string>
#include <iostream>

class Simulacao {
    CamadaFisicaTransmissora* transmissora;
    CamadaFisicaReceptora* receptora;
    BitArray* mensagem;

    Simulacao(int);
    ~Simulacao();

    void camadaDeAplicacaoTransmissora(std::string);
    void camadaDeAplicacaoReceptora();
    void meioDeComunicacao();
    void camadaFisicaTransmissora();
    void camadaFisicaReceptora();
};