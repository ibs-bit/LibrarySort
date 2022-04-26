//
// Created by io0om on 26/04/2022.
//

#ifndef LIBRARYSORT_NODE_H
#define LIBRARYSORT_NODE_H


#include "Book.h"

class Node {
public:
    Node(Book book, Node* right = nullptr, Node* left = nullptr);

    Book data;
    Node* left;
    Node* right;



};

/* Node* getRight();
 Node* getLeft();

 void setRight(Node* right);
 void setLeft(Node* left);
*/

#endif //LIBRARYSORT_NODE_H
