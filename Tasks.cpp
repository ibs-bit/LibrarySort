//
// Created by io0om on 25/04/2022.
//
#include <iostream>
#include <fstream>
#include "Tasks.h"
#include "BST.h"
#include "Book.h"

BST Tasks::fillTree()
{
    BST myTree;
    ifstream file;
    file.open(R"(C:\Users\io0om\OneDrive\Desktop\Files\ProjectFiles\C++\LibrarySort\books)");
    if(!file)
    {
        cout << "Error opening Books file\n";
    }
    string bookArray[4];
    string myString;
    Book* book = new Book();
    while(getline(file, myString))
    {
        size_t field2 = 0;
        size_t field1;
        for(int i =0; i <= 3; i++)
        {
            field1= myString.find("\t", field2);
            if (field1 != string::npos)
            {
                string str2 = myString.substr(field2, field1-field2);
                bookArray[i] = str2;
            }
            field2 = field1 + 1;
        }
        book->setTitle(bookArray[0]);
        book->setAuthor(bookArray[1]);
        book->setISBN(bookArray[2]);
        book->setQTY(bookArray[3]);
        myTree.insert(*book);

    }
    return myTree;
}