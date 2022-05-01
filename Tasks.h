//
// Created by io0om on 25/04/2022.
//

#ifndef LIBRARYSORT_TASKS_H
#define LIBRARYSORT_TASKS_H

#include "vector"
#include "LinkedList.h"
#include <iostream>
#include <istream>

class Tasks {
public:
    static void searchTitle(std::string title);
    static LinkedList loadData();
    static void printData();
    static LinkedList addBook(LinkedList list);
    static LinkedList removeBook(std::string title);
    static void timeComplexity(LinkedList list);

};

//    friend std::istream& operator>>(std::istream &is, Book& book);
//    friend std::ostream& operator<<(std::ostream& os, Book& book);
//    void searchBook(std::string title);
//    void loadVector(std::vector<Book>& bookRecord, std::string filename);
//    BST fillTree();
//    BST addBook(BST bst);
//    BST removeBook(std::string title);
//    void inOrder(Node* node);
//    void printOrder();

#endif //LIBRARYSORT_TASKS_H
