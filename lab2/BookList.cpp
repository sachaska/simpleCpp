// Ai Sun
// BookList.cpp
// Oct 1, 2023
// Implementation file for the BookList class used to add new books,
// print class to string and get size or empty status.

#include "BookList.h"
#include <sstream>
#include <random>

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

void BookList::add(string author, string title, string year) {
    Node* newNode = new Node(author, title, year, generate_isbn(MIN, MAX));

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

long BookList::generate_isbn(long min, long max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<long> distribution(min, max);
    long isbn_number = distribution(generator);
    return isbn_number;
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

