#pragma once
#include <string>
#include "Author.h"
using namespace std;

class Book {
    string title;
    Author author;
    int year;
    double price;
    string isbn;

    static int totalBooks;

public:
    Book();
    Book(const string& t, const Author& a, int y, double p, const string& i);

    Book(const Book& other) = default;
    Book(Book&& other) noexcept = default;
    Book& operator=(const Book& other) = default;
    Book& operator=(Book&& other) noexcept = default;
    ~Book() = default;

    const string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    const string& getISBN() const { return isbn; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    void setPrice(double p);
    void setYear(int y);

    static int getTotalBooks();

    string to_string() const;
};
