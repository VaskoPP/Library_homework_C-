#pragma once
#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
using namespace std;

class Library {
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;

public:
    void addBook(const Book& b) { books.push_back(b); }
    void addMember(const Member& m) { members.push_back(m); }

    bool hasBook(const string& isbn) const {
        for (const auto& b : books)
            if (b.getISBN() == isbn) return true;
        return false;
    }

    bool isBookAvailable(const string& isbn) const {
        for (const auto& l : loans)
            if (l.getISBN() == isbn && !l.isReturned())
                return false;
        return true;
    }

    bool loanBook(const string& isbn, const string& memberId,
                  const string& start, const string& due)
    {
        if (!hasBook(isbn)) return false;
        if (!isBookAvailable(isbn)) return false;

        loans.emplace_back(isbn, memberId, start, due);
        return true;
    }

    bool returnBook(const string& isbn, const string& memberId) {
        for (auto& l : loans)
            if (l.getISBN() == isbn && l.getMemberId() == memberId && !l.isReturned()) {
                l.markReturned();
                return true;
            }
        return false;
    }

    vector<Book> findByAuthor(const string& name) const {
        vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(name) != string::npos)
                result.push_back(b);
        return result;
    }

    string to_string() const {
        int activeLoans = 0;
        for (const auto& l : loans)
            if (!l.isReturned()) activeLoans++;

        return "Books: " + std::to_string(books.size()) +
               " | Members: " + std::to_string(members.size()) +
               " | Active loans: " + std::to_string(activeLoans);
    }
};
