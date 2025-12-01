#include "Loan.h"
#include <stdexcept>

Loan::Loan(const string& i, const string& m,
           const string& start, const string& due)
    : isbn(i), memberId(m), startDate(start), dueDate(due), returned(false)
{
    if (due < start)
        throw invalid_argument("Due date must be >= start date");
}

bool Loan::isOverdue(const string& today) const {
    return !returned && today > dueDate;
}

string Loan::to_string() const {
    return isbn + " -> " + memberId +
           " | " + startDate + " -> " + dueDate +
           (returned ? " (returned)" : " (active)");
}
