class CamadaFisicaReceptora {
public:
    virtual uint8_t *execute(uint8_t *) = 0;
};

class CFRBinaria : public CamadaFisicaReceptora {
public:
    uint8_t* execute(uint8_t *) override;
};

class CFRManchester : public CamadaFisicaReceptora {
public:
    uint8_t* execute(uint8_t *) override;
};

class CFRManchesterDiferencial : public CamadaFisicaReceptora {
public:
    uint8_t* execute(uint8_t *) override;
};
