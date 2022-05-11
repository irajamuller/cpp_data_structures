#include "StaticQueue.cpp"

using namespace std;

// Classe de Teste
int main() {
    StaticQueue<int> fila(20);
    std::cout << "Fila antes da inserção: " << fila << std::endl;
    for (int i = 1; i <= 15; i++)
        fila.enqueue(i);

    std::cout << "Fila depois da inserção: " << fila << std::endl;
    std::cout << "Fila vazia? " << fila.isEmpty() << std::endl;
    std::cout << "Fila cheia? " << fila.isFull() << std::endl;
    std::cout << "Número de elementos: " << fila.numElements() << std::endl;
    std::cout << "Qual elemento está no início da fila: " << fila.front() << std::endl;
    std::cout << "Removendo elemento do início da fila: " << fila.dequeue() << std::endl;
    std::cout << "Fila depois da remoção: " << fila << std::endl;

    return 0;
}



