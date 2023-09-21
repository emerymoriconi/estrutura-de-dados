typedef int TipoItem; //apenas definindo o tipo dos itens da pilha 
const int max_itens = 100;

class pilha{
    private:
    //somente a classe pode acessar
    int tamanho; //tamanho da pilha
    TipoItem* estrutura; //declarando estrutura da pilha (vetor) utilizando * para mais facilidade se precisar deletar a pilha

    public:
    pilha(); //função contrutora da pilha
    ~pilha(); //função destrutora da pilha
    bool esta_cheia(); //função que verifica se a pilha está cheia
    bool esta_vazia(); //função que verifica se a pilha está vazia
    void inserir(TipoItem item); //função para inserir na pilha (push)
    TipoItem remover(); //função para remover da pilha (pop)
    void imprimir(); //imprimir elementos da pilha
    int qual_tamanho(); //tamanho da pilha (lenght)
};