#include <cstdint>
#include <iostream>
#include "../include/Utils.hpp"

int printMenu() {

    int tipo_codigo;

    std::cout << std::endl << "Tipos de codificação: " << std::endl << std::endl;
    std::cout << "0) Codificação Binária" << std::endl;
    std::cout << "1) Codificação Manchester" << std::endl;
    std::cout << "2) Codificação Manchester Diferencial" << std::endl << std::endl;
    std::cout << "Digite o tipo de codificação que iremos utilizar: ";
    std::cin >> tipo_codigo;
    return tipo_codigo;
}
