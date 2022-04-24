#include <iostream>
#include <fstream>
#include <set>
#include "Node.h"

using namespace std;

void searchBook();
void addBook(string title);
void deleteBook(string title);
void mainMenu();

int main() {
    int choice =0;
    string title, author, isbn, qty;

    while(choice != 5) {

        mainMenu();
        cin >> choice;

        if (choice == 1){
            searchBook();
        }

    }
}

void mainMenu(){

    cout << "-  1  Searching for a Book        -\n";
    cout << "-  2  Add a new Book              -  \n";
    cout << "-  2  Remove a Book               -  \n";
    cout << "-  2  Calculate algorithm time    -  \n";
    cout << "-  2  Exit the program              -  \n";
}

void searchBook() {
    string title;
    Node Tree(0);
    Node* root = nullptr;
    int t;
    cin >> t;
    while(t--){
        Book data;
        cin >> data;
        root = Tree.search(root, data);
    }
}
