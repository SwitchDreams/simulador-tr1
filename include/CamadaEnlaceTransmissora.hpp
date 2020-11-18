#ifndef CET_HPP
#define CET_HPP

#include <iostream>
#include "BitArray.hpp"

class CamadaEnlaceTransmissora {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CETContagemCaracteres : public CamadaEnlaceTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

class CETInsercaoBytes : public CamadaEnlaceTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

class CETInsercaoBits : public CamadaEnlaceTransmissora {
public:
    BitArray* execute(BitArray *) override;
};

#endif // CET_HPP