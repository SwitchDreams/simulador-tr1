#ifndef SIMULACAO_HPP
#define SIMULACAO_HPP

#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/CamadaEnlaceTransmissora.hpp"
#include "../include/CamadaEnlaceReceptora.hpp"
#include "../include/CamadaTransmissoraControleDeErro.hpp"
#include "../include/CamadaReceptoraControleDeErro.hpp"
#include "../include/BitArray.hpp"
#include <string>
#include <iostream>

class Simulacao {
private:
    CamadaFisicaTransmissora* fisicaTransmissora;
    CamadaFisicaReceptora* fisicaReceptora;

    CamadaEnlaceTransmissora* enlaceTransmissora;
    CamadaEnlaceReceptora* enlaceReceptora;

    CamadaTransmissoraControleDeErro* erroTransmissora;
    CamadaReceptoraControleDeErro* erroReceptora;

    float propabilidadeErro;

public:
    Simulacao(int, int, int, int);
    ~Simulacao();

    /**** Transmissão ****/
    void camadaDeAplicacaoTransmissora(std::string);
    void camadaFisicaTransmissora(BitArray*);

    /**** Comunicação ****/
    void meioDeComunicacao(BitArray*);

    /**** Recepção ****/
    void camadaDeAplicacaoReceptora(BitArray*);
    void camadaFisicaReceptora(BitArray*);

    /**** Enlace ****/
    BitArray* camadaEnlaceTransmissoraEnquadramento(BitArray*);
    BitArray* camadaEnlaceReceptoraEnquadramento(BitArray*);
};

#endif // SIMULACAO_HPP