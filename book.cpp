#include "Book.h"
#include <stdexcept>

int Book::totalBooks = 0;

Book::Book()
    : title("Unknown"), author(), year(2000), price(0.0), isbn("N/A") {
    totalBooks++;
}

Book::Book(const string& t, const Author& a, int y, double p, const string& i)
    : title(t), author(a), year(y), price(p), isbn(i) 
{
    if (p < 0) throw invalid_argument("Price must be >= 0");
    if (y < 1500 || y > 2025) throw invalid_argument("Invalid year");
    if (i.empty()) throw invalid_argument("ISBN cannot be empty");
    totalBooks++;
}

void Book::setPrice(double p) {
    if (p < 0) throw invalid_argument("Price must be >= 0");
    price = p;
}

void Book::setYear(int y) {
    if (y < 1500 || y > 2025) throw invalid_argument("Invalid year");
    year = y;
}

int Book::getTotalBooks() {
    return totalBooks;
}

string Book::to_string() const {
    return title + " | " + author.to_string() + " | " +
           std::to_string(year) + " | " +
           std::to_string(price) + " лв | " + isbn;
}
