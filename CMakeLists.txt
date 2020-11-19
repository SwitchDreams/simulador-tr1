cmake_minimum_required(VERSION 3.13.4)
project(simulador-camada-fisica)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main src/main.cpp src/Utils.cpp src/Simulacao.cpp src/CamadaFisicaReceptora.cpp src/CamadaFisicaTransmissora.cpp src/CamadaEnlaceReceptora.cpp src/CamadaEnlaceTransmissora.cpp src/BitArray.cpp)
add_executable(Test src/test/BitArrayTest.cpp src/BitArray.cpp)