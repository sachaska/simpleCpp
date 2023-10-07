// Ai Sun
// BookList.cpp
// Oct 1, 2023
// Implementation file for the BookList class used to add new books,
// print class to string and get size or empty status.

#include "BookList.h"
#include <random>
#include <iostream>
#include <sstream>

BookList::BookList() {
    size = DEFAULT;
    list = new Book[size];
    number = 0;
}

BookList::~BookList() {
    delete[] list;
}

int BookList::getNumber() const {
    return number;
}

void BookList::add(const string& author, const string& title, const string& year) {
    number++;
    if (number > size)
        resize();
    int index = number - 1;
    list[index].author = author;
    list[index].title = title;
    list[index].year = year;
    list[index].isbn = generateIsbn(MIN, MAX);
}

bool BookList::isEmpty() const {
    return number == 0;
}

void BookList::resize() {
    size *= 2;
    Book * newList = new Book[size];
    for (int i = 0; i < number; i++) {
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;
}

long BookList::generateIsbn(long min, long max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<long> distribution(min, max);
    return distribution(generator);
}

string BookList::to_string() const {
    stringstream ss;
    if (isEmpty())
        return "";
    else {
        for (int i = 0; i < number; ++i) {
            ss << i + 1 << ", " << list[i].author << ", " <<
            list[i].title << ", " << list[i].year << endl;
        }
    }
    return ss.str();
}