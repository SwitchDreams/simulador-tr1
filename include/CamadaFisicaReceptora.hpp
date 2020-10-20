#include "Utils.hpp"
#include "BitArray.hpp"

class CamadaFisicaReceptora {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CFRBinaria : public CamadaFisicaReceptora {
public:
    BitArray *execute(BitArray *) override;
};

class CFRManchester : public CamadaFisicaReceptora {
public:
    BitArray *execute(BitArray *) override;
};

class CFRManchesterDiferencial : public CamadaFisicaReceptora {
public:
    BitArray *execute(BitArray *) override;
};
