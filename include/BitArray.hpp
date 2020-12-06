#ifndef BIT_ARRAY_HPP
#define BIT_ARRAY_HPP

#include <stdlib.h>
#include <string>

#define BYTE_SIZE 8 //!< Tamanho de um byte em bits
#define BYTE_FLAG (uint8_t) 0b1000000
#define BIT_FLAG (uint8_t) 0b01111110
#define BYTE_ESC (uint8_t) 0b00100011
#define BIT_8 (uint8_t) 0b10000000
#define BIT_1 (uint8_t) 0x01
#define TAM_QUADRO BYTE_SIZE


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
    uint8_t *container;
    unsigned int lenght; //!< Tamanho do BitArray em bytes
public:
    unsigned int lenghtBits;
    /**
     * @brief Inicializa o BitArray
     * Esse construtor recebe de parâmetro uma string e inicializa o ponteiro do container, convertendo cada char em
     * formato ascii e colocando em cada posição do array de uint8_t. Também atribui o valor de lenght como a
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
    *  @brief Coleta o primeiro o primeiro byte do array
    *
    * @return unsigned int com o valor do byte
    */
    unsigned int getCabecalho();

    /**
    * @brief Coleta o byte da posição especificada
    *
    * @return unsigned int com o valor do byte
    */
    unsigned int getByte(uint8_t posicao);

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
    void operator=(const BitArray &);

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

    /**
     * @brief Conta a quantidade de uns
     * @return unsigned int com a quantidade de 1 no quadro
     */
     unsigned int contBitsOne();

     void copyBits(BitArray*);
};

#endif // BIT_ARRAY_HPP