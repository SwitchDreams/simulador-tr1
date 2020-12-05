#ifndef CRCE_HPP
#define CRCE_HPP

#include <iostream>
#include <vector>
#include "BitArray.hpp"

class CamadaReceptoraControleDeErro {
public:
    virtual BitArray *execute(BitArray *) = 0;
};

class CRCEParidadePar : public CamadaReceptoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

class CRCEParidadeImpar : public CamadaReceptoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

class CRCECRC : public CamadaReceptoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

class CRCEHamming : public CamadaReceptoraControleDeErro {
public:
    BitArray* execute(BitArray *) override;
};

#endif // CRCE_HPP