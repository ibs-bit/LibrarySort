//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_NODE_H
#define LIBRARYSORT_NODE_H


#include <cstring>
#include "Book.h"

// Node class constructor
class Node {
private:
    Book data;
    Node* left;
    Node* right;
public:
    Node(Node* root, Book data);
    Book getData();
    void inorder(Node* root);
    Node * insert(Node* root, Book data);
    Node * deleteNode(Node* root, Book k);
    Node * search(Node* root, Book key);

};


#endif //LIBRARYSORT_NODE_H
