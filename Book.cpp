//
// Created by M00690877 on 24/04/2022.


#include <fstream>
#include <iostream>
#include <set>
#include "Book.h"

using namespace std;

Book::Book(string title, string author, string isbn, int qty)
{
    this->title = title;
    this->author = author;
    this->isbn =isbn;
    this->qty = qty;

}
Book::Book()
{
    title = "";
    author = "";
    isbn = "";
    qty = 0;

}
Book::~Book() {}

string Book::getTitle(){return title;}
string Book::getAuthor(){return author;}
string Book::getISBN(){return isbn;}
int Book::getQTY(){return qty;}

void Book::setTitle(string title){title = title;}
void Book::setAuthor(string author){author = author;}
void Book::setISBN(string isbn){isbn = isbn;}
void Book::setQTY(basic_string<char> qty){ qty = qty;}





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
    return;

}



