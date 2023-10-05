// Ai Sun
// BookList.cpp
// Oct 1, 2023
// Implementation file for the BookList class used to add new books,
// print class to string and get size or empty status.

#include "BookList.h"
#include <sstream>

BookList::BookList() {
    head = nullptr;
}

BookList::~BookList() {
    Node* element = head;
    while (element) {
        Node* temp = element;
        element = element->next;
        delete temp;
    }

}

void BookList::add(string author, string title, string year, long isbn) {
    Node* newNode = new Node(author, title, year, isbn);

    if (isEmpty())
        head = newNode;

    else {
        Node* element = head;

        while (element->next)
            element = element->next;

        element->next = newNode;
    }

}

bool BookList::isEmpty() {
    return head == nullptr;
}

int BookList::getSize() {
    const int EMPTY = 0;

    if (isEmpty())
        return EMPTY;

    else {
        int size = 1;
        Node* element = head;

        while (element->next) {
            size++;
            element = element->next;
        }

        return size;
    }

}

string BookList::to_string() {
    stringstream ss;

    if (isEmpty())
        return ss.str();

    else {
        Node *element = head;
        int count = 1;

        do {
            ss << count << ", " << element->author << ", " <<
            element->title << ", " << element->year << endl;
            element = element->next;
            count++;
        } while (element);

    }

    return ss.str();
}

