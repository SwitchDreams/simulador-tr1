#ifndef CTCE_HPP
#define CTCE_HPP

#include <iostream>
#include <vector>
#include "BitArray.hpp"

class CamadaTransmissoraControleDeErro {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CTCEParidadePar : public CamadaTransmissoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

class CTCEParidadeImpar : public CamadaTransmissoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

class CTCECRC : public CamadaTransmissoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

class CTCEHamming : public CamadaTransmissoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

#endif // CTCE_HPP