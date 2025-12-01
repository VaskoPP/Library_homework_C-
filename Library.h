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
    void addBook(const Book& b);
    void addMember(const Member& m);

    bool hasBook(const string& isbn) const;
    bool isBookAvailable(const string& isbn) const;
    bool loanBook(const string& isbn, const string& memberId,
                  const string& start, const string& due);
    bool returnBook(const string& isbn, const string& memberId);

    vector<Book> findByAuthor(const string& authorName) const;

    string to_string() const;
};
