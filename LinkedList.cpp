//
// Created by io0om on 01/05/2022.
//

#include "LinkedList.h"

Node* LinkedList::getHead(){return this->head;}
Node* LinkedList::getTail() {return this->tail;}

// true if there is no data in List
bool LinkedList::empty() {return this->head == nullptr;}


// This Function adds a new Book to the Head of the list.
void LinkedList::addtoList(Book data)
{
    // create a new node with the Book data
    Node* node = new Node(data, nullptr);

    // if list head is empty add it node to the head of the List;
    if(this->empty())
        this->head = node;
    else // otherwise add node to tail
        tail->setNext(node);

    this->tail = node;
}

Book LinkedList::searchBook(std::string title)
{
    Book book;
    Node* node = this->head;

    // traverse the entire list
    while(node != nullptr)
    {
        if(node->getData().getTitle() == title)
            return node->getData();
        node = node->getNext();

    }
    return book;
}


// this method removes a Book node from the list,
// it recursively calls getNext if the Book is not at the head.
Book LinkedList::removeBook(std::string title)
{
    Book data = Book();
    Node* curr = this->head;
    Node* prev = nullptr;

    // traverse while title doesn't match current node and points to another node.
    while(curr->getData().getTitle() != title && curr->getNext()!= nullptr)
    {
        prev = curr;
        curr = curr->getNext();
    }
    // if the title doesn't match and the curr node is at the tail delete curr node
    if(curr->getData().getTitle() != title && curr == tail)
    {
        delete curr;
        return data;
    }
    else if(curr == head)
    {
        this->head = this->head->getNext();
    }
    else // otherwise if the node is not at the tail of the list
    {    // set the previous node to the curr node next.
        if(curr!=this->tail)
            prev->setNext(curr->getNext());
        else
            prev->setNext(nullptr);

        this->tail = prev;
    }
    data = curr->getData();
    delete curr;

    return data;
}