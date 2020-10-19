#include <iostream>

class CamadaFisicaTransmissora {
public:
    virtual int *execute(int *) = 0;
};

class CFTBinaria : public CamadaFisicaTransmissora {
public:
    inline int* execute(int * mensagem) override {
        //std::cout << *mensagem << std::endl;
    }
};

class CFTManchester : public CamadaFisicaTransmissora {
public:
    int* execute(int *) override;
};

class CFTManchesterDiferencial : public CamadaFisicaTransmissora {
public:
    int* execute(int *) override;
};

