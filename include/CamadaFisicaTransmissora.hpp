#include <iostream>

class CamadaFisicaTransmissora {
public:
    virtual int *execute(int *) = 0;
};

class CFTBinaria : public CamadaFisicaTransmissora {
public:
    int* execute(int * mensagem) override;
};

class CFTManchester : public CamadaFisicaTransmissora {
public:
    int* execute(int *) override;
};

class CFTManchesterDiferencial : public CamadaFisicaTransmissora {
public:
    int* execute(int *) override;
};

