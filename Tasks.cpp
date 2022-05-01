#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <limits>
#include "Tasks.h"

using namespace std;

// method to load library data (books.txt) to Linked List
// declares a linked list and Book constructor
LinkedList Tasks::loadData()
{
    LinkedList list;
    Book* book = new Book();
    ifstream inFile("books");
    string bookArray[4];
    string line;

    while(getline(inFile,line))
    {
//        cout << "----------------------------------------------------------------------------------------------------\n";
//        cout << "    title          |               author(s)                |          isbn         |        qty     \n";
//        cout << "----------------------------------------------------------------------------------------------------\n";
        size_t field2 = 0;
        size_t field1;

        for (int i = 0; i <= 3; i++) {
            // values in the "books" file are delimited by a Tab;
            field1 = line.find('\t', field2);
            if (field1 != string::npos) {
                string str = line.substr(field2, field1 - field2);
                bookArray[i] = str;
            }

            field2 = field1 + 1;
        }
        // set values to Book data
        book->setTitle(bookArray[0]);
        book->setAuthor(bookArray[1]);
        book->setISBN(bookArray[2]);
        book->setQTY(stoi(bookArray[3]));

       // cout << book->getTitle() << "  " << book->getAuthor() << "   " << book->getISBN() << "    " << book->getQTY() << " records.\n";

              // add book to head of the List
        list.addtoList(*book);
    }

    return list;
}

void Tasks::searchTitle(std::string title)
{
    // load linked list with data
    LinkedList list = loadData();
    // search book with linked list method using the provided title
    Book book = list.searchBook(title);

    // if the Book item has values in it then print the Data
    if(!book.getTitle().empty())
    {
        cout << "----------------------------------------------------------------------------------------------------------\n";
        cout << "    title          |               author(s)                |          isbn         |        qty          \n";
        cout << "----------------------------------------------------------------------------------------------------------\n";
        cout << book.getTitle()<<"\t"<<book.getAuthor()
        <<"\t"<<book.getISBN()<<"\t"<<book.getQTY()<<"\t\n";
        cout << "----------------------------------------------------------------------------------------------------------\n";
    }
    else
    {
        cout << title <<"  |: not Found in the database\n";
    }
}


// Method to add new book to the database
LinkedList Tasks::addBook(LinkedList list)
{
    ofstream outFile("books", ios::out|ios::app);
    string newtitle, author, isbn;
    int qty;
    cout << ",--------------------------------------------------------------------\n";
    cout << "|    Enter Title : ";
    cin.ignore();
    getline(cin,newtitle);
    cout << "|--------------------------------------------------------------------\n";
    cout << "|    Enter author: ";
    getline(cin, author);
    cout << "|--------------------------------------------------------------------\n";
    cout << "|    Enter ISBN: ";
    getline( cin, isbn);
    cout << "|--------------------------------------------------------------------\n";
    cout << "|    Enter qty: ";
    cin >> qty;

    // input validation for in case of accidental input
    // create a new book and add it to the List head
    Book book = Book(newtitle,author,isbn,qty);

    outFile << newtitle <<"\t"<<author<<"\t"<<isbn<<"\t"<<qty<<"\t\n";
    outFile.close();
    cout << ",--------------------------------------------------------------------\n";
    cout << "| " << newtitle << ": added to the database                             \n";


    return list;
}



// this method removes a book by calling the loadData() method to store
// to the list and calls removeBook algorithm in the Linked List file.

 LinkedList Tasks::removeBook(std::string title)
{
    Book book;
    LinkedList list = loadData();
    cout << endl;
    book = list.removeBook(std::move(title));

    if(!book.getTitle().empty())
    {
        ofstream outFile;
        outFile.open("books");
        Node* curr = list.getHead();

        while(curr != nullptr)
        {
            string newTitle  = curr->getData().getTitle();
            string author = curr->getData().getAuthor();
            string isbn = curr->getData().getISBN();
            int qty = curr->getData().getQTY();

            outFile << newTitle << "\t" << author << "\t" << isbn << "\t" << qty << "\t\n";
            curr = curr->getNext();
        }
        outFile.close();
//        remove("books");
//        rename("temp","books");

        cout <<"Removed :  " << book.getTitle() << "  from the database\n";
    } else
        cout << "No Book under this title is present at the database\n";
    return list;
}

void Tasks::timeComplexity(LinkedList list)
{
    int choice;
    string option;


    cout << ",------------------------------------------\n";
    cout << "| 1- Time Complexity of Search algorithm   \n";
    cout << "|                                          \n";
    cout << "| 2- Time Complexity of Delete algorithm   \n";
    cout << "|_________________________________________ \n";
    cout << "| Select an Option                      :   ";

    cin >> choice;

    // input validation for in case of accidental input
    if (!cin){
        cout << "\n____Wrong input, Enter again______________" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<< "Enter a valid number from the menu: ";
    }
    cout << "|_________________________________________ \n";
    Book book;
    string title;
    int count, bookCount = 1;
    float time = 0;
    clock_t start, end;

    start = clock(); // start clock time
    Node* curr = list.getHead();
    while (curr->getNext()!= nullptr)
    {
        curr = curr->getNext();
        bookCount +=1;
    }



    (choice == 1) ? option="|  Time Complexity of Search algorithm  " : option="|  Time Complexity of Delete algorithm   ";
    cout << ",------------------------------------------\n";
    cout << "| Books counted  = " << bookCount << "\n";
    cout << "|_________________________________________ \n";
    cout << option <<"                             \n";



    switch(choice)
    {
        // Search time Evaluation
        case 1:
            for(int i = 1;i<=bookCount; i = i * 2)
            {
                curr = list.getHead();
                count = 1;
                if(2* i >= bookCount)
                    i = bookCount;

                while(curr != nullptr) {
                    if (count == i) {
                        // search for book title
                        title = curr->getData().getTitle();
                        book = list.searchBook(title);
                        end = clock();
                        book.getISBN();
                        time = static_cast<float>(end - start) / CLOCKS_PER_SEC;
                        cout << "| Time taken     = " << time << "  seconds \n";
                        cout << "|_________________________________________ \n";
                        break;
                    }
                    count+=1;
                    curr = curr->getNext();
                }
            }
            break;
        case 2:
            list = loadData();
            for(int i = 1;i<=bookCount; i = i * 2)
            {
                curr = list.getHead();
                count = 1;
                if(2* i >= bookCount)
                    i = bookCount;

                while(curr != nullptr) {
                    if (count == i) {
                        title = curr->getData().getTitle();
                        list.removeBook(title);
                        end = clock(); // end clock time
                        time = static_cast<float>(end - start) / CLOCKS_PER_SEC;
                        cout << "\n| Time taken     = " << time << "  seconds \n";
                        cout << "|_________________________________________ \n";
                        break;
                    }
                    count+=1;
                    curr = curr->getNext();
                }
            }
            break;
    }

}

// Print the library Data base from the /books file
// iterates through lines and takes books to array items
void Tasks::printData() {
    Book* book = new Book();
    ifstream inFile("books");
    string bookArray[4];
    string line;

    while(getline(inFile,line))
    {
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << "    title          |               author(s)                |          isbn         |        qty     \n";
        cout << "----------------------------------------------------------------------------------------------------\n";
        size_t field2 = 0;
        size_t field1;

        for (int i = 0; i <= 3; i++) {
            // values in the "books" file are delimited by a Tab;
            field1 = line.find("\t", field2);
            if (field1 != string::npos) {
                string str = line.substr(field2, field1 - field2);
                bookArray[i] = str;
            }

            field2 = field1 + 1;
        }
        // set values to Book data
        book->setTitle(bookArray[0]);
        book->setAuthor(bookArray[1]);
        book->setISBN(bookArray[2]);
        book->setQTY(stoi(bookArray[3]));

        cout << book->getTitle() << "  " << book->getAuthor() << "   " << book->getISBN() << "    " << book->getQTY() << " records.\n";

    }
}

