#include <iostream>
#include "../include/Utils.hpp"

int getMenuCodigo() {

    int tipo_codigo;

    std::cout << std::endl << "Tipos de codificação: " << std::endl << std::endl;
    std::cout << "0) Codificação Binária" << std::endl;
    std::cout << "1) Codificação Manchester" << std::endl;
    std::cout << "2) Codificação Manchester Diferencial" << std::endl << std::endl;
    std::cout << "Digite o tipo de codificação que iremos utilizar: ";
    std::cin >> tipo_codigo;
    return tipo_codigo;
}

int getMenuEnquadramento() {
    int tipo_codigo;

    std::cout << std::endl << "Tipos de enquadramento: " << std::endl << std::endl;
    std::cout << "0) Contagem de Caracteres" << std::endl;
    std::cout << "1) Inserção de Bytes" << std::endl;
    std::cout << "2) Inserção de Bits" << std::endl << std::endl;
    std::cout << "Digite o tipo de enquadramento que iremos utilizar: ";
    std::cin >> tipo_codigo;
    return tipo_codigo;
}