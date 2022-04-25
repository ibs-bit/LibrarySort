//
// Created by io0om on 24/04/2022.
//

#include <iostream>
#include <utility>
#include "BST.h"



bool BST::isEmpty() const{
    return root == nullptr;
}

void BST::search(string key)
{
    bool found = false;
    if(isEmpty())
    {
        cout << " This Tree is empty! " << endl;
        return;
    }

    node* curr;
    curr = root;

    while(curr!= nullptr)
    {
        if(curr->data.getTitle() == key)
        {
            found = true;
            curr->data.getTitle();
            break;
        }
        else
        {
            if(key>curr->data.getTitle())
                curr = curr->right;
            else
                curr = curr->left;
        }
    }
    if (!found)
    {
        cout << "data not found\n";
        return;
    }
}

void BST::insert(Book book)
{
    node* n = new node;
    node* parent;
    n->data = std::move(book);
    n->left  = nullptr;
    n->right = nullptr;
    parent = nullptr;

    if(isEmpty())
        root = n;
    else{
        node* curr;
        curr = root;

        while(curr)
        {
            parent = curr;
            if(n->data.getTitle() > curr->data.getTitle())
                curr = curr->right;
            else
                curr = curr->left;
        }
        if(n->data.getTitle() < parent->data.getTitle())
            parent->left  = n;
        else
            parent->right = n;
    }
}


// function to remove a book.
void BST::remove(string book) {
    bool found = false;
    if (isEmpty()) {
        cout << "Tree has no variables inside!\n";
        return;
    }
    node *curr;
    node *parent;
    curr = root;

    while (curr != nullptr) {
        if (curr->data.getTitle() == book) {
            found = true;
            break;
        } else {
            parent = curr;
            if (book > curr->data.getTitle())
                curr = curr->right;
            else
                curr = curr->left;
        }
    }
    if (!found) {
        cout << "Data not found\n";
        return;
    }

    // if the node has one child.
    if ((curr->left == nullptr && curr->right != nullptr) || (curr->left != nullptr
                                                              && curr->right == nullptr)) {
        if (curr->left == nullptr && curr->right != nullptr) {
            if (parent->left == curr) {
                parent->left = curr->right;
                delete curr;
            } else {
                parent->right = curr->right;
                delete curr;
            }
        } else // if there is a left child node but no right child node.
        {
            if (parent->left == curr) {
                parent->left = curr->left;
                delete curr;
            } else {
                parent->right = curr->left;
                delete curr;
            }
        }
        return;
    }
    // if we are looking for a leaf node
    if (curr->left == nullptr && curr->right == nullptr) {
        if (parent->left == curr)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete curr;
        return;
    }
    // if the node has 2 children
    // we replace it with smallest value in the right-sub tree
    if (curr->left != nullptr && curr->right != nullptr) {
        node *change;
        change = curr->right;
        if ((change->left == nullptr) && (change->right == nullptr)) {
            curr = change;
            delete change;
            curr->right = nullptr;
        } else // if the right child node has a child
        {
            // if the right child node has a left child traverse down left
            // until the smallest element is located
            if ((curr->right)->left != nullptr) {
                node *lcurr;
                node *pLcurr;
                pLcurr = curr->right;
                lcurr = (curr->right)->left;
                while (lcurr->left != nullptr) {
                    //set left node as parent node and child as left.
                    pLcurr = lcurr;
                    lcurr = lcurr->left;
                }
                curr->data = lcurr->data;
                delete lcurr;
                pLcurr->left = nullptr;
            } else {
                node *tmp;
                tmp = curr->right;
                curr->data = tmp->data;
                curr->left = tmp->right;
                delete tmp;
            }
        }
        return;
    }
}

