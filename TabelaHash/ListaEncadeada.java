package TabelaHash;

public class ListaEncadeada {
    public class No {
        public int valor;
        public int chave;
        public No proximo;
        
        public No(int chave, int valor) {
            this.valor = valor;
            this.chave = chave;
            proximo = null;
        }
    }

    private No primeiro;
    
    public ListaEncadeada() {
        primeiro = null;
    }

    // complexidade maior que se fosse no inicio
    public void inserirNoFinal(int chave, int valor) {
        No novo = new No(chave, valor);
        novo.proximo = null;
        if (primeiro == null) {
            primeiro = novo;
        } else {
            No atual = primeiro;
            while (atual.proximo != null) {
                atual = atual.proximo;
            }
            atual.proximo = novo;
        }
    }

    public void remover(int chave, int valor) {
        No anterior = null;
        No atual = primeiro;
        while (atual != null && atual.chave != chave && atual.valor != valor) {
            anterior = atual;
            atual = atual.proximo;
        }
        if (atual != null) {
            if (anterior == null) {
                primeiro = atual.proximo;
            } else {
                anterior.proximo = atual.proximo;
            }
        }
    }

    public boolean pesquisar(int chave, int valor){
        for (No atual = primeiro; atual != null; atual = atual.proximo) {
            if (atual.chave == chave && atual.valor == valor) return true;
        }
        return false;
    }

    public void exibir() {
        for (No atual = primeiro; atual != null; atual = atual.proximo) {
            System.out.print("[" + atual.chave + ", " + atual.valor + "] ");
        }
    }
}
