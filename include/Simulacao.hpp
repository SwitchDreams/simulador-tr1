#include "../include/CamadaFisicaTransmissora.hpp"
#include "../include/CamadaFisicaReceptora.hpp"
#include "../include/BitArray.hpp"

class Simulacao {
    CamadaFisicaTransmissora* transmissora;
    CamadaFisicaReceptora* receptora;
    BitArray* mensagem;

    Simulacao(int tipo_codificacao);
    ~Simulacao();

    void camadaDeAplicacaoTransmissora(string mensagem);
    void camadaDeAplicacaoReceptora();
    void meioDeComunicacao();
    void camadaFisicaTransmissora();
    void camadaFisicaReceptora();
};