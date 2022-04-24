//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_BOOK_H
#define LIBRARYSORT_BOOK_H

#include <string>
#include "Node.h"

using namespace std;

// Book constructor
class Book : public Book, public Node {
private:
    string title;
    string author;
    string isbn;
    int qty;
public:
    Book(string title, string author, string isbn, int qty);
    Book();
    ~Book();

    string getTitle();
    string getAuthor();
    string getISBN();
    int getQTY();


    void setTitle(string title);
    void setAuthor(string author);
    void setISBN(string isbn);
    void setQTY(int qty);

};


#endif //LIBRARYSORT_BOOK_H
