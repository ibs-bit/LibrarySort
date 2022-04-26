//
// Created by io0om on 26/04/2022.
//

#include "Node.h"

Node::Node(Book book, Node* right, Node* left)
:data(book),right(right),left(left)
{
}

/*Node* Node::getLeft() {return this->left;}
Node* Node::getRight() { return this->right;}

void Node::setRight(Node* right) { this->right = right;}
void Node::setLeft(Node *left) {this->left = left;}*/