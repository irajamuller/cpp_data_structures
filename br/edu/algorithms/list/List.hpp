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
class List
{
public:
    virtual int numberOfElements() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void insert(const E& element, int pos) = 0;
    virtual E remove(int pos) = 0;
    virtual const E& get(int pos) = 0;
    virtual int search(const E& element) = 0;
};