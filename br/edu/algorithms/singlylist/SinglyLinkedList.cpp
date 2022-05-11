/**  
 * Baseado no livro Data Structures and Algorithm Analysis
 * Edição 3.2 - Clifford A. Shaffer
 * Link https://people.cs.vt.edu/shaffer/Book/C++3elatest.pdf
 * Página: A partir da página 121
 *
*/

#pragma once

#include <stdexcept>
#include <iostream>
#include "../list/List.hpp"
#include "Node.cpp"

#define INIT_CAPACITY 10

using namespace std;

template <typename E>

// Classe concreta (materializa o ADT)
class SinglyLinkedList: public List<E>
{
protected:
    Node<E>* head;
    Node<E>* tail;
    int numElements;

public:
    SinglyLinkedList() {
        head = tail = NULL;
        numElements = 0;
    }         
    ~SinglyLinkedList() {
        Node<E>* current = head;
        while (current != NULL) {
            head = current;
            current = current->next;
            delete head;
        }
    }                      
    int numberOfElements() override {
        return numElements;
    }
    bool isEmpty() override {
        return numElements == 0;
    }
    bool isFull() override {
        return false;
    }
    void insertFirst(const E& element) {
        Node<E>* newNode = new Node<E>(element);
        if (isEmpty())
            head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        numElements++;
    }
    void insertLast(const E& element) {
        Node<E>* newNode = new Node<E>(element);
        if (isEmpty())
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        numElements++;
    }

    void insert(const E& element, int pos) override {
        if (pos < 0 || pos > numElements)
            throw std::runtime_error("Invalid position!");
        if (pos == 0)
            insertFirst(element);
        else if (pos == numElements)
            insertLast(element);
        else {
            Node<E>* prev = head;    
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            Node<E>* newNode = new Node<E>(element);
            newNode->next = prev->next;
            prev->next = newNode;
            numElements++;
        }
    }
    E removeFirst() {
        if (isEmpty())
            throw std::runtime_error("List is Underflow");
        E element = head->element;
        if (head == tail)
            head = tail = NULL;
        else 
            head = head->next;
        numElements--;
        return element;
    }
    E removeLast() {
        if (isEmpty())
            throw std::runtime_error("List is Underflow");
        E element = tail->element;
        if (head == tail)
            head = tail = NULL;
        else {
            Node<E>* prev = head;    
            while (prev->next != tail)
                prev = prev->next;
            tail = prev;
            prev->next = NULL;
        }
        numElements--;
        return element;
    }
    E remove(int pos) override {
        if (pos < 0 || pos >= numElements)
            throw std::runtime_error("Invalid position!");
        if (pos == 0)
            return removeFirst();
        else if (pos == numElements - 1)
            return removeLast();
        else {
            Node<E>* prev = head;    
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;
            E element = prev->next->element;
            prev->next = prev->next->next;
            numElements--;
            return element;
        }
    }
    const E& get(int pos) override {
        if (pos < 0 || pos >= numElements)
            throw std::runtime_error("Invalid position!");
        Node<E>* current = head;    
        for (int i = 0; i < pos; i++)
            current = current->next;
        return current->element;
    }
    int search(const E& element) override {
        Node<E>* current = head;    
        int i = 0;
        while (current != NULL) {
            if (current->element == element)
                return i;
            current = current->next;
            i++;
        }
        return -1;
    }
    friend ostream &operator<<(ostream &out, SinglyLinkedList &list) {
        if (list.isEmpty()) 
            return out << "[empty]";
        Node<E>* current = list.head;
        out << "[";
        while (current->next != NULL) {
            out << current->element << ", ";
            current = current->next;
        }
        return out << current->element << "]";
    }    
};