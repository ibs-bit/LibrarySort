
//
// Created by io0om on 30/04/2022.
//

#define CATCH_CONFIG_MAIN

#include "../Tasks.h"
#include "catch.hpp"

Tasks task;
// Load library data to List
LinkedList list;

Book book1;

// test case to load data books file data to Linked List
TEST_CASE("Load data to Linked List", "[loadData()]"){

    // load data and require that the first book has at least 1 copy.
    list = task.loadData();

    REQUIRE(list.getHead()->getData().getQTY() > 0);


}


//  test case to search for a Book
TEST_CASE("search for book by title", "[searchBook(), searchTitle()]"){

    // book  at the near head of the list
    std::string title = "Recursive Algorithms";
    list = task.loadData();
    book1 = list.searchBook(title);
    // search book that is in the middle of the list
    std::string title2 = "Linear Programming and Economic Analysis";
    Book book2 = list.searchBook(title2);


    // search book the tail of the list
    std::string title3  = "Graph Databases";
    Book book3 = list.searchBook(title3);

    // the retrieved book object's title should identical to the given title.
    REQUIRE(book1.getTitle() == title);
    REQUIRE(book2.getTitle() == title2);
    REQUIRE(book3.getTitle() == title3);


}


// test case to adding a Book to database.
TEST_CASE("Add new Book" , "[addBook(list)]")
{
    // create a new book and insert it to the List
    Book book = Book("TestCase Book","John Doe", "3877762123",1);
    list.addtoList(book);
    // get the most last inserted item in the list to a Book node
    // and compare it to the new Book values.
    Node* curr = list.getTail();
    std::string nTitle = curr->getData().getTitle();
    std::string nauthor = curr->getData().getAuthor();
    std::string nisbn = curr->getData().getISBN();
    int nqty = curr->getData().getQTY();

    // they should have the same values
    REQUIRE(book.getTitle() == nTitle);
    REQUIRE(book.getAuthor() == nauthor);
    REQUIRE(book.getISBN()==nisbn);
    REQUIRE(book.getQTY()== nqty);

}


TEST_CASE("removing a book" ,"removeBook(title)" )
{
    // remove the head of the list,
    list = task.loadData();
    Node* head = list.getHead();
    std::string title = head->getData().getTitle();
    list.removeBook(title);
    // and require that previous head node's title
    REQUIRE(head->getData().getTitle()!= title);
}

