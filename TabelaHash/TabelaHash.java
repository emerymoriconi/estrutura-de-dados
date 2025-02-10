package TabelaHash;

public class TabelaHash {
    // Tamanho da tabela hash -> Número Primo
    private static final int TAMANHO = 11;
    private int indice;
    // Array de listas
    private ListaEncadeada[] tabela;

    // Construtor -> Inicia uma lista pra cada posição do array
    public TabelaHash() {
        tabela = new ListaEncadeada[TAMANHO];
        for (int i = 0; i < TAMANHO; i++) {
            tabela[i] = new ListaEncadeada();
        }
    }

    public int FuncaoHash(int chave){
        return chave % TAMANHO;
    }

    // Método para inserir um elemento na tabela hash
    public void inserir(int chave, int valor) {
        indice = FuncaoHash(chave);
        tabela[indice].inserirNoFinal(chave, valor);
    }

    // Método para remover um elemento da tabela hash
    public void remover(int chave, int valor) {
        indice = FuncaoHash(chave);
        tabela[indice].remover(chave, valor);
    }

    // Método para pesquisar um elemento na tabela hash
    public boolean pesquisar(int chave, int valor) {
        indice = FuncaoHash(valor);
        return tabela[indice].pesquisar(chave, valor);
    }

    // Método para exibir a tabela hash
    public void exibir() {
        for (int i = 0; i < TAMANHO; i++) {
            System.out.print("Índice " + i + ": ");
            tabela[i].exibir();
            System.out.println();
        }
    }
}