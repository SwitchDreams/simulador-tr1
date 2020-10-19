class CamadaFisicaReceptora {
public:
    virtual int *execute(int *) = 0;
};

class CFRBinaria : public CamadaFisicaReceptora {
public:
    int* execute(int *) override;
};

class CFRManchester : public CamadaFisicaReceptora {
public:
    int* execute(int *) override;
};

class CFRManchesterDiferencial : public CamadaFisicaReceptora {
public:
    int* execute(int *) override;
};
