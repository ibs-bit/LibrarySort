//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_BOOK_H
#define LIBRARYSORT_BOOK_H

#include <string>

using namespace std;

class Book{
private:
    string title;
    string author;
    string isbn;
    int qty;
public:
    // Book constructor
    Book();
    Book(string title, string author, string isbn, int qty);
    ~Book();



    string getTitle();
    string getAuthor();
    string getISBN();
    int getQTY();


    void setTitle(string title);
    void setAuthor(string author);
    void setISBN(string isbn);
    void setQTY(basic_string<char> qty);
    void sortBooks();

};


#endif //LIBRARYSORT_BOOK_H
