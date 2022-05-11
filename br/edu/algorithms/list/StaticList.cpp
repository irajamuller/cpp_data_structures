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
#include "List.hpp"

#define INIT_CAPACITY 10

using namespace std;

template <typename E>

// Classe concreta (materializa o ADT)
class StaticList: public List<E>
{
protected:
    int size;
    int numElements;
    E* elements;    

public:
    StaticList(int capacity = INIT_CAPACITY) {
        size = capacity;
        numElements = 0;
        elements = new E[size];
    }         
    ~StaticList() {
        delete [] elements;
    }                      
    int numberOfElements() override {
        return numElements;
    }
    bool isEmpty() override {
        return numElements == 0;
    }
    bool isFull() override {
        return numElements == size;
    }
    void insert(const E& element, int pos) override {
        if (isFull())
            throw std::runtime_error("Queue is Overflow!");
        if (pos < 0 || pos > numElements)
            throw std::runtime_error("Invalid position!");
        for (int i = numElements - 1; i >= pos; i--)
            elements[i + 1] = elements[i];
        elements[pos] = element;
        numElements++;    
    }
    E remove(int pos) override {
        if (isEmpty())
            throw std::runtime_error("List is Underflow!");
        if (pos < 0 || pos >= numElements)
            throw std::runtime_error("Invalid position!");
        
        E element = elements[pos];
        for (int i = pos; i < numElements - 1; i++)
            elements[i] = elements[i + 1];
        numElements--;
        return element;
    }
    const E& get(int pos) override {
        if (pos < 0 || pos >= numElements)
            throw std::runtime_error("Invalid position!");
        return elements[pos];
    }
    int search(const E& element) override {
        for (int i = 0; i < numElements; i++)
            if (element == elements[i])
                return i;
        return -1;
    }
    friend ostream &operator<<(ostream &out, StaticList &list) {
        if (list.isEmpty()) 
            return out << "[empty]";
        out << "[";
        for (int i = 0; i < list.numElements - 1; i++) {
            out << list.elements[i] << ", ";
        }
        return out << list.elements[list.numElements - 1] << "]";
    }
};