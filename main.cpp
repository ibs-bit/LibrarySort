#include <iostream>
#include <fstream>
#include "BST.h"
#include "Book.h"
#include "Tasks.h"

using namespace std;

void searchBook();
void mainMenu();
void print(){ BST bst; bst.printInorder();}
void fillTree()
{
    BST bst;
    ifstream file;
    file.open(R"(C:\Users\io0om\OneDrive\Desktop\Files\ProjectFiles\C++\LibrarySort\books)");
    if(!file)
    {
        cout << "Error opening Books file\n";
    }
    string bookArray[4];
    string myString;
    Book book;
    while(getline(file, myString))
    {
        size_t field2 = 0;
        size_t field1 = myString.find("\t");
        for(int i =0; i <= 2; i++)
        {
            size_t field1 = myString.find("\t", field2);
            if (field1 != string::npos)
            {
                string str2 = myString.substr(field2, field1-field2);
                bookArray[i] = str2;
            }
            field2 = field1 + 1;
        }
        book.setTitle(bookArray[0]);
        book.setAuthor(bookArray[1]);
        book.setISBN(bookArray[2]);
        book.setQTY("0");
        cout << book.getTitle()<<"   " << book.getAuthor()<<" " << book.getISBN()<<"   " << book.getQTY() << endl;
        Book newBook = Book(bookArray[0],bookArray[1],bookArray[2],bookArray[3]);
        bst.insert(newBook);
        cout << "-----------------------------------------\n";
        cout << "Book  " << book.getAuthor() << "  saved\n";

    }
}

int main() {
    fillTree();
    int choice =0;
    while(choice != 5) {
        mainMenu();
        cin >> choice;

        if (choice == 1){
            searchBook();
        }
        else if (choice == 2)
        {
            print();
        }

    }
}

void mainMenu(){

    cout << "-----------------------------------  \n";
    cout << "-  1  Searching for a Book        -  \n";
    cout << "-  2  Add a new Book              -  \n";
    cout << "-  3  Remove a Book               -  \n";
    cout << "-  4  Calculate algorithm time    -  \n";
    cout << "-  5  Exit the program            -  \n";
    cout << "-----------------------------------  \n";
    cout << "- Enter your selection:  ";
}

void searchBook()
{
    BST bst;
    string key;

    cout << "Enter Title of the Book : ";
    cin.ignore();
    getline(cin,key);
    bst.search(key);
}

