/**  
 * Baseado no livro Data Structures and Algorithm Analysis
 * Edição 3.2 - Clifford A. Shaffer
 * Link https://people.cs.vt.edu/shaffer/Book/C++3elatest.pdf
 * Página: A partir da página 121
 *
*/

#pragma once

template <typename E>

// ADT 
class Queue
{
public:
    virtual int numElements() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void enqueue(const E& element) = 0;
    virtual E dequeue() = 0;
    virtual const E& front() = 0;
};