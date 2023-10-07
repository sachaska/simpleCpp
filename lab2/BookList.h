// Ai Sun
// BookList.h
// Oct 1, 2023
// Specification file for the BookList class used to add new books,
// print class to string and get size or empty status.

#ifndef LAB2_BOOKLIST_H
#define LAB2_BOOKLIST_H


#include <string>
using namespace std;

class BookList {
public:
    BookList();
    // Default constructor
    // precondition: none
    // postcondition: initialize the array

    ~BookList();
    // Default destructor
    // precondition: none
    // postcondition: head is deleted

    long generateIsbn(long, long);
    // ISBN generator
    // precondition: none
    // postcondition: return ISBN

    void add(const string&, const string&, const string&);
    // Add Node in BookList
    // precondition: none
    // postcondition: new Node is added to the tail of BookList

    bool isEmpty() const;

    int getNumber() const;

    string to_string() const;
    // Overwrite default to_string function
    // precondition: none
    // postcondition: return string contains contents of BookList and formant

private:
    struct Book {
        string author;          // the author of Book
        string title;           // the title of Book
        string year;            // the year of Book
        long isbn;              // the isbn number of Book
        // precondition: none
        // postcondition: node being created
    };
    void resize();
    int number;                                                 // index
    int size;                                                   // size
    static const int DEFAULT = 20;                              // default size
    Book* list;                                                 // list of books
    const long MIN = 1000000000000, MAX = 9999999999999; // ISBN range
};




#endif //LAB2_BOOKLIST_H
