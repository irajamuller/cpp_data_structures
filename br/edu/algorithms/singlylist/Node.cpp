/**  
 * Baseado no livro Data Structures and Algorithm Analysis
 * Edição 3.2 - Clifford A. Shaffer
 * Link https://people.cs.vt.edu/shaffer/Book/C++3elatest.pdf
 * Página: A partir da página 121
 *
*/

#pragma once

template <typename E>

// Pode ser utilizado struct
class Node
{
public:
    E element;    
    Node *next; 

    Node(const E& element, Node* next = NULL) {
        this->element = element;
        this->next = next;
    }         
};