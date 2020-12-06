#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

int getMenuCodigo();
int getMenuEnquadramento();
int getControleErro();
int getChanceDeErro();
void insereBytesComoBits(uint8_t, std::vector<uint8_t>*);
bool isPow2(unsigned int);

#endif // UTILS_HPP