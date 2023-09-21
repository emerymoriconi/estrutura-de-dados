#include <iostream> //saídas
#include "pilha.h" //arquivo criado ("")

using namespace std;

//Lógica LIFO: Last In, First Out
//Lógica FILO: First In, Last Out
/*Aplicações:
    -- Abas no computador: abas no computador são organizadas em pilhas na memória, já que a última aba a ser acessada e fechada é colocada no topo da pilha.
    -- Botão de voltar: é uma pilha, já que a aba que será retornada é a aba que está no topo da pilha do botão de voltar, a última aba acessada (LIFO). 
    -- Botão de avançar: é uma pilha, já que quando o botão de voltar é pressionado, a aba que antes era a aba atual, será colocada no topo da pilha do botão de avançar, fazendo dela a aba seguinte a ser acessada.
    -- Editor de texto: tudo que está sendo feito é colocado no topo da pilha e quando algo for desfeito, a ação no topo da pilha é acessada (Ex: Ctrl + Z).
*/

//Implementação de Pilha com Vetores

    pilha::pilha() //função contrutora da pilha
    {
        tamanho = 0; //não há elementos na pilha inicialmente
        estrutura = new TipoItem[max_itens];
    }

    pilha::~pilha() //função destrutora da pilha
    {
        delete [] estrutura; 
    }

    bool pilha::esta_cheia() //função que verifica se a pilha está cheia
    {
        return (tamanho == max_itens); //retorna true se o tamanho da pilha for igual ao número máximo de itens, caso contrário retorna false
    }

    bool pilha::esta_vazia() //função que verifica se a pilha está vazia
    {
        return (tamanho == 0); //retorna true se o tamanho da pilha for igual a zero, caso contrário retorna false
    }

    void pilha::inserir(TipoItem item) //função para inserir na pilha (push)
    {
        if (esta_cheia()){
            cout << "A pilha está cheia!\n";
            cout << "Nao é possível inserir este elemento!\n";
        } else {
            estrutura[tamanho] = item;
            tamanho++;
        }
    }

    TipoItem pilha::remover() //função para remover da pilha (pop)
    {
        if (esta_vazia()){
            cout << "A pilha está vazia!\n";
            cout << "Não existem elementos para serem removidos!\n";
            return 0;
        } else {
            tamanho--;
            return estrutura[tamanho];
        }
    }

    void pilha::imprimir() //imprimir elementos da pilha
    {
        cout << "Pilha: [ ";
        for (int i=0; i<tamanho; i++){
            cout << estrutura[i] << " ";
        }
        cout << "]\n";
    }

    int pilha::qual_tamanho() //tamanho da pilha (lenght)
    {
        return tamanho;
    }