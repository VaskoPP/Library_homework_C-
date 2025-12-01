#pragma once
#include <string>
using namespace std;

class Loan {
    string isbn;
    string memberId;
    string startDate;
    string dueDate;
    bool returned;

public:
    Loan(const string& isbn, const string& memberId,
         const string& start, const string& due);

    void markReturned() { returned = true; }
    bool isReturned() const { return returned; }

    bool isOverdue(const string& today) const;
    const string& getISBN() const { return isbn; }
    const string& getMemberId() const { return memberId; }

    string to_string() const;
};
