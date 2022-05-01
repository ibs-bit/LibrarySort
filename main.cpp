#include <iostream>
#include <limits>
#include "Tasks.h"


using namespace std;


// method to print main menu
void mainMenu(){

    cout << ",--------------------------------------------------------------------\n";
    cout << "|    1  Print Library Data              \n";
    cout << "|    2  Searching for a Book           \n";
    cout << "|    3  Add a new Book                \n";
    cout << "|    4  Remove a Book                 \n";
    cout << "|    5  Calculate algorithm time      \n";
    cout << "|    6  Print in Alphabetical order (saves to 'sortedBooks' file)       \n";
    cout << "|    7  Exit the program              \n";
    cout << "|--------------------------------------------------------------------\n";
    cout << "- Enter your selection:  ";
}






//main method

int main()
{
    // declare the Task handler class and the linked list
    LinkedList list = Tasks::loadData();
    int choice =0;


    // keep in the menu
    while(choice != 7)
    {
        mainMenu();

        cin >> choice;
        // input validation for in case of accidental input
        if (!cin){
            cout << "\n|   Wrong input, Enter again______________" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "|    Enter a valid number from the menu: \n";
        }
        if (choice == 1){
            // print data of the Library
            Tasks::printData();

        }
        else if (choice == 2){

            // input title and search function is called from tasks
            string key;
            cout << "Enter Title of the Book : ";
            cin.ignore();
            getline(cin,key);
            Tasks::searchTitle(key);
        }
        else if (choice == 3)
        {
            // handler for adding book
          list = Tasks::addBook(list);
        }
        else if (choice == 4)
        {
            // handler for removing a book
            string title;
            cout << "Enter Title of the Book to remove:  ";
            cin.ignore();
            getline(cin,title);
            list = Tasks::removeBook(title);
        }
        else if (choice == 5)
        {
            // handler for evaluating time complexity
            Tasks::timeComplexity(list);

        }
        else if (choice == 6)
        {
            // handler for evaluating time complexity
            Book::sortBooks();

        }
        else
            cout << "|--------------------------------------------------------------------\n";

    }

    cout << "\n     Library  Program has Ended                          \n" << std::endl;
    return 0;
}

