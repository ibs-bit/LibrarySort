//
// Created by M00690877 on 24/04/2022.


#include "Book.h"

using namespace std;


Book::Book(string bTitle, string bAuthor, string bIsbn, int bQty)
{
    title = bTitle;
    author = bAuthor;
    isbn = bIsbn;
    qty = bQty;
}

Book::Book()
{
    title = "";
    author = "";
    isbn = "";
    qty = 0;
}

Book::~Book() {}

string Book::getTitle(){return this->title;}
string Book::getAuthor(){return this->author;}
string Book::getISBN(){return this->isbn;}
int Book::getQTY(){return this->qty;}

void Book::setTitle(string title){this->title = title;}
void Book::setAuthor(string author){this->author = author;}
void Book::setISBN(string isbn){this->isbn = isbn;}
void Book::setQTY(int qty){this->qty = qty;}

    /* ifstream input(R"(C:\Users\io0om\OneDrive\Desktop\Files\ProjectFiles\C++\LibrarySort\books)");
     fstream output;
     output.open(R"(C:\Users\io0om\OneDrive\Desktop\Files\ProjectFiles\C++\LibrarySort\books)", ios::app);

     if (!input.is_open()) {
         cout << "Error opening file" << endl;
         return 1;
     }

     set<string> sortedBooks;
     string book;

     while (getline(input, book)) {
         sortedBooks.insert(book);
     }
     for (const auto &n: sortedBooks) {
         cout << n << endl;
         output << n << endl;
     }
     input.close();
     return 0; */



