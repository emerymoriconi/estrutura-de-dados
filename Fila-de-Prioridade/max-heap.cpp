#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    private:
        vector<int> heap;

        // funções auxiliares
        int pai(int i) {
            return (i - 1) / 2;
        }

        int esquerdo(int i) {
            return 2 * i + 1;
        }

        int direito(int i) {
            return 2 * i + 2;
        }

        void heapUp(int i) {
            // enquanto o nó novo que chegou no final do array (adicionado por push_back) for maior que o pai dele
            // troca o nó com o pai dele
            while (i > 0 && heap[pai(i)] < heap[i]) {
                swap(heap[i], heap[pai(i)]);
                i = pai(i);
            }
        }

        void heapDown(int i) {
            int esq = esquerdo(i);
            int dir = direito(i);
            int maior = i;

            // se o nó da esquerda for maior que o nó atual
            if (esq < heap.size() && heap[esq] > heap[i]) {
                maior = esq;
            }

            // se o nó da direita for maior que o nó atual
            if (dir < heap.size() && heap[dir] > heap[maior]) {
                maior = dir;
            }

            // se o maior nó não for o nó atual
            if (maior != i) {
                swap(heap[i], heap[maior]);
                heapDown(maior);
            }
        }


    public:
        void push(int value) {
            heap.push_back(value);
            heapUp(heap.size() - 1);
        }
    
        void pop() {
            if (heap.empty()) return;
            heap[0] = heap.back();
            heap.pop_back();
            heapDown(0);
        }
    
        int top() {
            if (heap.empty()) throw runtime_error("Heap está vazia");
            return heap[0];
        }
    
        bool empty() {
            return heap.empty();
        }
};