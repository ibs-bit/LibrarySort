//
// Created by io0om on 24/04/2022.
//

#include "BST.h"

BST::BST() {
    this->root = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}

Node* BST::getRoot()
{
    return this->root;

}

bool BST::isEmpty()
{
    return this->root == nullptr;
}

Book BST::searchBook(string title)
{
    Book book = Book();
    Node* temp;

    if(this->isEmpty())
        return book;

    temp = this->root;
    if (temp->getData().getTitle() == title)
        return temp->getData();

}