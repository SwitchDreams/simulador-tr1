#ifndef BIT_ARRAY
#define BIT_ARRAY

#include <stdlib.h>
#include <string>

#define BYTE_SIZE 8 //!< Tamanho de um byte em bits

/*
 *  Classe BitArray
 *  Responsável pelo armazenamento da mensagem em formato binário
 * */
class BitArray {
private:
    /*
     * Para poupar espaço de memória, o container armazena em cada índice do array em char, porém todas as operações
     * seguintes abstrai o container para ser operado a nível de bits. Sendo que o MSB é a posição 0 dentro de um termo
     * de um container e respectivamente a LSB é a posição 1
     */
    u_int8_t *container;
    unsigned int lenght; //!< Tamanho do BitArray em bytes
public:
    /**
     * @brief Inicializa o BitArray
     * Esse construtor recebe de parâmetro uma string e inicializa o ponteiro do container, convertendo cada char em
     * formato ascii e colocando em cada posição do array de u_int8_t. Também atribui o valor de lenght como a
     * quantidade de chars da string passada de parametro.
     * @param mensagem: String da mensagem que será armazenada em bits
     * @return BitArray
     */
    BitArray(const std::string &);

    /**
    * @brief Destructor: Libera o espaço de memória do ponteiro do container
    */
    ~BitArray();

    /**
     * @brief Atribui 1 na posição passada por parametro do array
     * @param k: posição do bit no array
     * @return void
     */
    void setBit(unsigned int);

    /**
    * @brief Atribui 0 na posição passada por parametro do array
    * @param k: posição do bit no array
    * @return void
    */
    void clearBit(unsigned int);

    /**
    * @brief Overload do operator[] para retornar o valor da posição do array
    * @param k: posição do bit no array
    * @return Retorna um int o valor da posição k no array (0 ou 1)
    */
    int operator[](unsigned int);

    /**
    * @brief Printa no terminal o array de bits
    */
    void print();

};

#endif // BIT_ARRAY