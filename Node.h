//
// Created by io0om on 26/04/2022.
//

#ifndef LIBRARYSORT_NODE_H
#define LIBRARYSORT_NODE_H


#include "Book.h"

struct Node {
public:
    Node* next;
    Book data;

    // constructor and getters
    Node(Book book, Node* next);
    Book getData();
    Node* getNext();
    void setNext(Node* next);

};

#endif //LIBRARYSORT_NODE_H
