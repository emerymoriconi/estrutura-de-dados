// fila = queue
typedef int TipoItem; // tipo fixo dos elementos que compõem a fila
const int max_itens = 100; // declaração de constante - tamanho máximo da estrutura

class fila {
    private:
    int primeiro, ultimo; // "ponteiros"
    TipoItem* estrutura; // vetor declarado com estrutura 

    public:
    fila(); // construtor
    ~fila(); // destrutor
    bool estavazio(); // isempty
    bool estacheio(); //isfull
    void inserir(TipoItem item); // push // enqueue
    TipoItem remover(); //pop //dequeue
    void imprimir(); // print
};