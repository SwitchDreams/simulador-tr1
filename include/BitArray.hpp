#ifndef BIT_ARRAY_HPP
#define BIT_ARRAY_HPP

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
public:
    unsigned int lenght; //!< Tamanho do BitArray em bytes
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
     * @brief Inicializa o BitArray
     * Esse construtor recebe de parâmetro um tamanho do BitArray e preenche com zeros
     * @param tam: Tamanho do vetor
     * @return BitArray
     */
    BitArray(int);

    /**
    * @brief Destructor: Libera o espaço de memória do ponteiro do container
    */
    ~BitArray();

    /**
     * @brief Retorna o tamanho do container
     * 
     * @return unsigned int com o tamanho do container
     */
    unsigned int tam();

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
     * @brief Overload do operator = , para realizar a atribuição entre dois BitArrays
     * @param ba: endereço do BitArray que fornecerá os dados
     * @return void
     */
    void operator = (const BitArray&);

    /**
     * @brief Converte um array de bits para std::string
     * 
     * @return std::string 
     */
    std::string toString();

    /**
    * @brief Printa no terminal o array de bits
    */
    void print();

};

#endif // BIT_ARRAY_HPP