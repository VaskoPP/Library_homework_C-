#include "Author.h"
#include <stdexcept>

Author::Author() : name("Unknown"), birthYear(1900) {}

Author::Author(const string& n, int y)
    : name(n), birthYear(y) {
    if (y < 1850 || y > 2025)
        throw invalid_argument("Invalid birth year");
}

void Author::setBirthYear(int y) {
    if (y < 1850 || y > 2025)
        throw invalid_argument("Invalid birth year");
    birthYear = y;
}

string Author::to_string() const {
    return name + " (" + std::to_string(birthYear) + ")";
}
