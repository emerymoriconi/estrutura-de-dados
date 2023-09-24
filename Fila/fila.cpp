#include <iostream>
#include "fila.h"

using namespace std;

/* Lógica: FIFO - First In, First Out
Prioridades: fila de prioridades
A fila vai estar vazia quando os dois ponteiros (o que aponta pro inicio da fila e o outro que aponta pro final) estiverem apontando pro mesmo lugar.
Remoção (pop): reajusta o ponteiro do início da fila.
Adição (push): reajusta o ponteiro do final da fila.
A fila vai estar cheia quando os dois ponteiros estiverem à (quantidade máxima de elementos do vetor) de distância.
A fila "anda para frente" de forma circular.
*/

    fila::fila() // construtor
    {
        primeiro = 0;
        ultimo = 0;
        estrutura = new TipoItem[max_itens];
    }
    
    fila::~fila() // destrutor
    {
        delete [] estrutura;
    }

    bool fila::estavazio() // isempty
    {
        return (primeiro == ultimo);
    }

    bool fila::estacheio() //isfull
    {
        return (ultimo - primeiro == max_itens);
    }

    void fila::inserir(TipoItem item) // push // enqueue
    {
        if (estacheio()){
            cout << "A fila esta cheia!\n";
            cout << "Esse elemento nao pode ser inserido.";
        } else {
            estrutura[ultimo % max_itens] = item;
            ultimo++;
        }
    }

    TipoItem fila::remover() //pop //dequeue
    {
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nenhum elemento foi removido.";
            return 0;
        } else {
            primeiro++;
            return estrutura[(primeiro-1) % max_itens];
        }
    }

    void fila::imprimir() // print
    {
        cout << "Fila: [ ";
        for(int i=primeiro; i<ultimo; i++){
            cout << estrutura[i % max_itens] << " ";
        }
        cout << "]\n";
    }