//
// Created by io0om on 26/04/2022.
//

#include "Node.h"


// constructor and setter and getter declarations


Node::Node(Book book, Node* next)
{
    this->data = book;
    this->next = next;
}

Book Node::getData() {return this->data;}
Node* Node::getNext() {return this->next;}

void Node::setNext(Node* next) { this->next = next;}

