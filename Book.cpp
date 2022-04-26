//
// Created by M00690877 on 24/04/2022.


#include <fstream>
#include <iostream>
#include <set>
#include "Book.h"

using namespace std;

Book::Book(string title, string author, string isbn, string qty)
{
    this->title = title;
    this->author = author;
    this->isbn =isbn;
    this->qty = qty;

}
/*Book::Book(string btitle, string bauthor, string bisbn, string bqty)
{
    title = btitle;
    author = bauthor;
    isbn =bisbn;
    qty = bqty;

}*/
Book::Book()
{
    title = "";
    author = "";
    isbn = "";
    qty = "";

}
Book::~Book() {}

string Book::getTitle(){return this->title;}
string Book::getAuthor(){return this->author;}
string Book::getISBN(){return this->isbn;}
string Book::getQTY(){return this->qty;}

void Book::setTitle(string title){this->title = title;}
void Book::setAuthor(string author){this->author = author;}
void Book::setISBN(string isbn){this->isbn = isbn;}
void Book::setQTY(string qty){ this->qty = qty;}





// function to sort the books in an ascending order
void Book::sortBooks() {

    ifstream input(R"(C:\Users\io0om\OneDrive\Desktop\Files\ProjectFiles\C++\LibrarySort\books)");
    ofstream output(R"(C:\Users\io0om\OneDrive\Desktop\Files\ProjectFiles\C++\LibrarySort\sortedBooks)");

    if (!input.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    set <string> sortedBooks;
    string book;

    while (getline(input, book)) {
        sortedBooks.insert(book);
    }
    for (const auto &n: sortedBooks) {
        cout << n << endl;
        output << n << endl;
    }
    input.close();
    output.close();
    return;

}



