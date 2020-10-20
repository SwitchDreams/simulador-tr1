#include <stdlib.h>
#include <string>

#define BIT_SIZE 8

class BitArray {
private:
    u_int8_t* container;
    unsigned int lenght;
public:
    BitArray(const std::string&);
    ~BitArray();

    void setBit(unsigned int);
    void clearBit(unsigned int);

    int operator [] (unsigned int);

    // uint8_t &operator [] (unsigned int);
    void print();

};
