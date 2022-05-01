//
// Created by io0om on 24/04/2022.
//

#ifndef LIBRARYSORT_BOOK_H
#define LIBRARYSORT_BOOK_H

#include <string>



struct Book{
private:
    // member variables for the Book object.
    std::string title;
    std::string author;
    std::string isbn;
    int qty;
public:
    // Book constructor and destructor
    Book();
    Book(std::string title, std::string author, std::string isbn, int qty);
    ~Book();


    // getters and setters
    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();
    int getQTY();


    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setISBN(std::string isbn);
    void setQTY(int qty);

    // sort books file in alphabetical order
    static void sortBooks();

};


#endif //LIBRARYSORT_BOOK_H
