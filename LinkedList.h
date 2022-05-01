//
// Created by io0om on 01/05/2022.
//

#ifndef LIBRARYSORT_LINKEDLIST_H
#define LIBRARYSORT_LINKEDLIST_H


#include "Node.h"

class LinkedList{
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    Node* getHead();
    Node* getTail();
    bool empty();
    void addtoList(Book data);
    Book searchBook(std::string title);
    Book removeBook(std::string title);


};


#endif //LIBRARYSORT_LINKEDLIST_H
