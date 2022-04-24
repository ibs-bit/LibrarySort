//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_BST_H
#define LIBRARYSORT_BST_H


#include "Node.h"

class BST {
private:
    Node* root;
    Node* right;
    Node* left;
public:
    Node* getRoot();
    bool isEmpty();
    BST();
    ~BST();

    void insert(Book book);
    Book searchBook(string title);
    BST removeBook(Book book);

};


#endif //LIBRARYSORT_BST_H
