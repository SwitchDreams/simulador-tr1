#include <iostream>
#include "Utils.hpp"
#include "BitArray.hpp"


class CamadaFisicaTransmissora {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CFTBinaria : public CamadaFisicaTransmissora {
public:
    BitArray* execute(BitArray * mensagem) override;
};

class CFTManchester : public CamadaFisicaTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

class CFTManchesterDiferencial : public CamadaFisicaTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

