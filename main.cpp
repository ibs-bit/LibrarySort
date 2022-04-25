#include <iostream>
#include "BST.h"
#include "Book.h"
#include "Tasks.h"

using namespace std;

void searchBook();
void mainMenu();

int main() {
    int choice =0;

    while(choice != 5) {

        mainMenu();
        cin >> choice;

        if (choice == 1){
            searchBook();
        }
        else if (choice == 2)
        {

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
    BST bst = Tasks::fillTree();
    string key;
    cout << "Enter Title of the Book : ";
    cin.ignore();
    getline(cin,key);
    bst.search(key);
}

