//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_BST_H
#define LIBRARYSORT_BST_H

#include "Book.h"

class BST {
private:
    struct node{
        node* left;
        node* right;
        Book data;
    };
    node* root;

public:
    // constructor and destructor

    BST()
    {
       root = nullptr;
    }
    void search(string key);
    void insert(Book);
    void remove(string);
    void changeQTY(string key, int newQty);

    bool isEmpty() const;      // is true if the BST is empty.
};


#endif //LIBRARYSORT_BST_H
