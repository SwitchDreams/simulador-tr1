#include <iostream>
#include "Utils.hpp"

class CamadaFisicaTransmissora {
public:
    virtual uint8_t *execute(uint8_t *) = 0;
};

class CFTBinaria : public CamadaFisicaTransmissora {
public:
    uint8_t* execute(uint8_t * mensagem) override;
};

class CFTManchester : public CamadaFisicaTransmissora {
public:
    uint8_t* execute(uint8_t *) override;
};

class CFTManchesterDiferencial : public CamadaFisicaTransmissora {
public:
    uint8_t* execute(uint8_t *) override;
};

