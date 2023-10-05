// Ai Sun
// lab2.cpp
// Oct 1st
// Purpose: Read input file and populate the array of books.
// Input: The name of input file
// Process: Use BookList class, read the file from file path,
// populate data in file and display the contents.
// Output: Data in file.

#include <iostream>
#include <fstream>
#include <sstream>
#include "BookList.h"

using namespace std;

bool readFile(BookList&);
// This function reads in file and populate data in BookList
// IN: a BookList object, long variable for random range
// MODIFY: add data to BookList object
// OUT: returns a status refer to action successful or not

void print(BookList&);
// This function prints data from BookList object with format
// IN: a BookList object
// MODIFY: none
// OUT: none

string getFilePath();
// This function gets file path from user input
// IN: none
// MODIFY: none
// OUT: a string contains user input

int main() {
    const long MIN = 1000000000000, MAX = 9999999999999;
                    // const variable for range
    BookList *bookList;
    bookList = new BookList;      // BookList object

    if (readFile(*bookList))
        print(*bookList);

    delete bookList;

    return 0;
}

void print(BookList& book) {
    cout << "# of books: "<< book.getSize() << endl;
    cout << endl;
    cout << book.to_string();
}

string getFilePath() {
    string filepath;
    cout << "Enter books file: ";
    cin >> filepath;
    cout << endl;
    return filepath;
}

bool readFile(BookList& book) {
    ifstream inFile;
    inFile.open(getFilePath());
    string tempStr, author, title, year;

    if (inFile) {

        while (getline(inFile, tempStr)) {
            stringstream ss(tempStr);
            getline(ss, author, ',');
            getline(ss, title, ','),
            getline(ss, year);
            book.add(author, title, year);
        }

    }
    else {
        cout << "ERROR: cannot open file.\n";
        return false;
    }

    inFile.close();
    return true;
}