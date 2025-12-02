#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Loan {
    string isbn;
    string memberId;
    string startDate;
    string dueDate;
    bool returned;

public:
    Loan(const string& i, const string& m,
         const string& start, const string& due)
        : isbn(i), memberId(m), startDate(start), dueDate(due), returned(false)
    {
        if (due < start)
            throw invalid_argument("Due date must be >= start date");
    }

    void markReturned() { returned = true; }
    bool isReturned() const { return returned; }

    bool isOverdue(const string& today) const {
        return !returned && today > dueDate;
    }

    const string& getISBN() const { return isbn; }
    const string& getMemberId() const { return memberId; }

    string to_string() const {
        return isbn + " -> " + memberId +
               " | " + startDate + " -> " + dueDate +
               (returned ? " (returned)" : " (active)");
    }
};
