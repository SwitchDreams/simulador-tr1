#ifndef CER_HPP
#define CER_HPP

#include <iostream>
#include <string>
#include "BitArray.hpp"

class CamadaEnlaceReceptora {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CERContagemCaracteres : public CamadaEnlaceReceptora {
public:
    BitArray* execute(BitArray *) override;
};

class CERInsercaoBytes : public CamadaEnlaceReceptora {
public:
    BitArray* execute(BitArray *) override;
};

class CERInsercaoBits : public CamadaEnlaceReceptora {
public:
    BitArray* execute(BitArray *) override;
};

#endif // CER_HPP