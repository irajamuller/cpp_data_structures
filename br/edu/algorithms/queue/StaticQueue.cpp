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
#include "Queue.hpp"

#define INIT_CAPACITY 10

using namespace std;

template <typename E>

// Classe concreta (materializa o ADT)
class StaticQueue: public Queue<E>
{
protected:
    int size;
    int last;
    E* elements;    

public:
    StaticQueue(int capacity = INIT_CAPACITY) {
        size = capacity;
        last = -1;
        elements = new E[size];
    }         
    ~StaticQueue() {
        delete [] elements;
    }                      
    int numElements() override {
        return last + 1;
    }
    bool isEmpty() override {
        return last == -1;
    }
    bool isFull() override {
        return last == size - 1;
    }
    void enqueue(const E& element) override {
        if (isFull())
            throw std::runtime_error("Queue is Overflow!");
        elements[++last] = element;
    }
    E dequeue() override {
        if (isEmpty())
            throw std::runtime_error("Queue is Underflow!");
        E element = elements[0];
        for (int i = 0; i < last; i++)
            elements[i] = elements[i + 1];
        last--;
        return element;
    }
    const E& front() override {
        if (isEmpty())
            throw std::runtime_error("Queue is Underflow!");
        return elements[0];
    }
    friend ostream &operator<<(ostream &out, StaticQueue &queue) {
        if (queue.isEmpty()) 
            return out << "[empty]";
        out << "[";
        for (int i = 0; i < queue.last; i++) {
            out << queue.elements[i] << ", ";
        }
        return out << queue.elements[queue.last] << "]";
    }
};