#include "SinglyLinkedList.cpp"

using namespace std;

// Classe de Teste
int main() {
    SinglyLinkedList<int> lista;
    std::cout << "Lista antes da inserção: " << lista << std::endl;
    for (int i = 1; i <= 15; i++) 
        lista.insert(i, i - 1);

    std::cout << "Lista depois da inserção: " << lista << std::endl;
    lista.insertFirst(30);
    lista.insertLast(40);
    std::cout << "Lista depois da inserção: " << lista << std::endl;
    std::cout << "Lista vazia? " << lista.isEmpty() << std::endl;
    std::cout << "Lista cheia? " << lista.isFull() << std::endl;
    std::cout << "Número de elementos: " << lista.numberOfElements() << std::endl;
    std::cout << "Removendo elemento do início da lista: " << lista.removeFirst() << std::endl;
    std::cout << "Removendo elemento do final da lista: " << lista.removeLast() << std::endl;
    std::cout << "Removendo elemento do meio da lista: " << lista.remove(lista.numberOfElements() / 2) << std::endl;
    std::cout << "Lista depois da remoção: " << lista << std::endl;
    std::cout << "Elemento da posição 3 da lista: " << lista.get(3) << std::endl;
    std::cout << "Elemento 10 está em qual posição da lista? " << lista.search(10) << std::endl;

    return 0;
}



