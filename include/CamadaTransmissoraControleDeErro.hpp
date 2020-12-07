#ifndef CTCE_HPP
#define CTCE_HPP

#include <iostream>
#include <vector>
#include "BitArray.hpp"

class CamadaTransmissoraControleDeErro {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CTCEParidade : public CamadaTransmissoraControleDeErro {
public:
    BitArray* execute(BitArray *, bool isPar);
};

class CTCEParidadePar : public CTCEParidade {
public:
    BitArray* execute(BitArray *) override;
};

class CTCEParidadeImpar : public CTCEParidade {
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