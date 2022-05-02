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
#include "Stack.hpp"

#define INIT_CAPACITY 10

using namespace std;

template <typename E>

// Classe concreta (materializa o ADT)
class StaticStack: public Stack<E>
{
protected:
    int size;
    int top;
    E* elements;    

public:
    StaticStack(int capacity = INIT_CAPACITY) {
        size = capacity;
        top = -1;
        elements = new E[size];
    }         
    ~StaticStack() {
        delete [] elements;
    }                      
    int numElements() override {
        return top + 1;
    }
    bool isEmpty() override {
        return top == -1;
    }
    bool isFull() override {
        return top == size - 1;
    }
    void push(const E& element) override {
        if (isFull())
            throw std::runtime_error("Stack is Overflow!");
        elements[++top] = element;
    }
    E pop() override {
        if (isEmpty())
            throw std::runtime_error("Stack is Underflow!");
        return elements[top--];
    }
    const E& peek() override {
        if (isEmpty())
            throw std::runtime_error("Stack is Underflow!");
        return elements[top];
    }
    friend ostream &operator<<(ostream &out, StaticStack &stack) {
        if (stack.isEmpty()) 
            return out << "[empty]";
        out << "[";
        for (int i = stack.numElements() - 1; i >= 1; i--) {
            out << stack.elements[i] << ", ";
        }
        return out << stack.elements[0] << "]";
    }
};