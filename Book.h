#pragma once
#include <string>
#include <stdexcept>
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
    Book()
        : title("Unknown"), author(), year(2000), price(0.0), isbn("N/A")
    {
        totalBooks++;
    }

    Book(const string& t, const Author& a, int y, double p, const string& i)
        : title(t), author(a), year(y), price(p), isbn(i)
    {
        if (p < 0) throw invalid_argument("Price must be >= 0");
        if (y < 1500 || y > 2025) throw invalid_argument("Invalid year");
        if (i.empty()) throw invalid_argument("ISBN cannot be empty");
        totalBooks++;
    }

    // Rule of 5 (defaulted)
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

    void setPrice(double p) {
        if (p < 0) throw invalid_argument("Price must be >= 0");
        price = p;
    }

    void setYear(int y) {
        if (y < 1500 || y > 2025) throw invalid_argument("Invalid year");
        year = y;
    }

    static int getTotalBooks() { return totalBooks; }

    string to_string() const {
        return title + " | " + author.to_string() + " | "
             + std::to_string(year) + " | "
             + std::to_string(price) + " лв | " + isbn;
    }
};

int Book::totalBooks = 0;
