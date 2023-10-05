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
    // postcondition: head is assigned to nullptr

    ~BookList();
    // Default destructor
    // precondition: none
    // postcondition: head is deleted

    long generate_isbn(long, long);
    // ISBN generator
    // precondition: none
    // postcondition: return ISBN

    void add(string author, string title, string year);
    // Add Node in BookList
    // precondition: none
    // postcondition: new Node is added to the tail of BookList

    bool isEmpty();
    // Check whether BookList is empty
    // precondition: none
    // postcondition: return empty status

    int getSize();
    // Get LinkList size
    // precondition: none
    // postcondition: return size

    string to_string();
    // Overwrite default to_string function
    // precondition: none
    // postcondition: return string contains contents of BookList and formant

private:
    struct Node {
        string author;          // the author of Book
        string title;           // the title of Book
        string year;            // the year of Book
        long isbn;              // the isbn number of Book
        struct Node * next;     // pointer to next node

        Node(string& a, string& t, string& y, long i) : author(a), title(t),
                                                        year(y), isbn(i), next(nullptr){}
        // Constructor
        // precondition: none
        // postcondition: node being created
    };

    Node *head;                 // head Node
    const long MIN = 1000000000000, MAX = 9999999999999; // ISBN range
};




#endif //LAB2_BOOKLIST_H
