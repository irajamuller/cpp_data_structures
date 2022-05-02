#include "StaticStack.cpp"

using namespace std;

// Classe de Teste
int main() {
    StaticStack<int> pilha(20);
    std::cout << "Pilha antes da inserção: " << pilha << std::endl;
    for (int i = 1; i <= 15; i++)
        pilha.push(i);

    std::cout << "Pilha depois da inserção: " << pilha << std::endl;
    std::cout << "Pilha vazia? " << pilha.isEmpty() << std::endl;
    std::cout << "Pilha cheia? " << pilha.isFull() << std::endl;
    std::cout << "Número de elementos: " << pilha.numElements() << std::endl;
    std::cout << "Qual elemento está no topo: " << pilha.peek() << std::endl;
    std::cout << "Removendo elemento do topo: " << pilha.pop() << std::endl;
    std::cout << "Pilha depois da remoção: " << pilha << std::endl;

    return 0;
}



