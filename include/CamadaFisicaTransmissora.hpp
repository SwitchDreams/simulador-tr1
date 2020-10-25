#ifndef CFT_HPP
#define CFT_HPP

#include <iostream>
#include <stdlib.h>
#include "Utils.hpp"
#include "BitArray.hpp"


class CamadaFisicaTransmissora {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CFTBinaria : public CamadaFisicaTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

class CFTManchester : public CamadaFisicaTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

class CFTManchesterDiferencial : public CamadaFisicaTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

#endif // CFT_HPP