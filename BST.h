//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_BST_H
#define LIBRARYSORT_BST_H

#include "Book.h"
#include "Node.h"


class BST {
private:
    Node* root;
public:
    // constructor and destructor

    BST();
    Node* getRoot();
    void search(string key);
    void insert(Book book);
    void remove(string);
    void changeQTY(string key, int newQty);
    void inorder(Node*);
    void printInorder();

    bool isEmpty() const;      // is true if the BST is empty.
};


#endif //LIBRARYSORT_BST_H
