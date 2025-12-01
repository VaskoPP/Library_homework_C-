#include "Library.h"

void Library::addBook(const Book& b) {
    books.push_back(b);
}

void Library::addMember(const Member& m) {
    members.push_back(m);
}

bool Library::hasBook(const string& isbn) const {
    for (const auto& b : books)
        if (b.getISBN() == isbn) return true;
    return false;
}

bool Library::isBookAvailable(const string& isbn) const {
    for (const auto& l : loans)
        if (l.getISBN() == isbn && !l.isReturned())
            return false;
    return true;
}

bool Library::loanBook(const string& isbn, const string& memberId,
                       const string& start, const string& due)
{
    if (!hasBook(isbn)) return false;
    if (!isBookAvailable(isbn)) return false;

    loans.emplace_back(isbn, memberId, start, due);
    return true;
}

bool Library::returnBook(const string& isbn, const string& memberId) {
    for (auto& l : loans)
        if (l.getISBN() == isbn && l.getMemberId() == memberId && !l.isReturned()) {
            l.markReturned();
            return true;
        }
    return false;
}

vector<Book> Library::findByAuthor(const string& name) const {
    vector<Book> result;
    for (const auto& b : books)
        if (b.getAuthor().getName().find(name) != string::npos)
            result.push_back(b);
    return result;
}

string Library::to_string() const {
    int activeLoans = 0;
    for (const auto& l : loans)
        if (!l.isReturned()) activeLoans++;

    return "Books: " + std::to_string(books.size()) +
           " | Members: " + std::to_string(members.size()) +
           " | Active loans: " + std::to_string(activeLoans);
}
