//
// Created by io0om on 24/04/2022.
//

#include <iostream>
#include "Node.h"

using namespace std;



// function to insert a Node to the tree
Node * Node::insert(Node* root, Book data){
    if (root == NULL)
    {
        return new Node(data);
    }
    else{
        Node* cur;
        if(data <= root->data)
        {
            cur = insert(root->left, data);
            root->left = cur;
        }else{
            cur = insert(root->right, data);
            root->right = cur;
        }
    }
}

// function to traverse the tree in order.
void Node::inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// search function
Node * Node::search(Node* root, Book key){
    if (root == nullptr || root->data == key)
        return root;
    //search variable is greater than the root
    if(root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}
Node * Node::deleteNode(Node* root, Book k)
{
    // base class
    if (root == NULL)
        return root;
    //if root is greater than input
    if(root->data > k){
        root->left = deleteNode(root->left, k);
        return root;
    }
    // if root is less than input
    else if(root->data < k){
        root->right = deleteNode(root->right, k);
        return root;
    }

    if (root->left == NULL)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    } else{
        Node* Parent = root;
        // find successor of node
        Node *succ = root->right;
        while(succ->left != NULL)
        {
            Parent = succ;
            succ = succ->left;
        }
        if(Parent != root)
            Parent->left = succ->right;
        else
            Parent->right = succ->right;
        root->data = succ->data;

        delete succ;
        return root;
    }
}