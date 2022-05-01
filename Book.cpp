//
// Created by M00690877 on 24/04/2022.


#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include "Book.h"

using namespace std;

Book::Book(string title, string author, string isbn, int qty)
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
void Book::setQTY(int qty){ this->qty = qty;}





// function to sort the books in an ascending order
void Book::sortBooks() {

    ifstream input("books");
    ofstream output("sortedBooks", ios::out|ios::app);

    if (!input.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    set <string> sortedBooks;
    string book;
    istringstream iss(book);

    while (getline(input, book)) {
        sortedBooks.insert(book+"\t");
    }
    for (const auto &n: sortedBooks)
    {
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << "    title          |               author(s)                |          isbn         |        qty     \n";
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout <<" "<< n << endl;
       // output << n << endl;
    }
    input.close();
    output.close();

}



