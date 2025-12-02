#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Author {
    string name;
    int birthYear;

public:
    Author() : name("Unknown"), birthYear(1900) {}

    Author(const string& n, int y)
        : name(n), birthYear(y)
    {
        if (y < 1850 || y > 2025)
            throw invalid_argument("Invalid birth year");
    }

    const string& getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y) {
        if (y < 1850 || y > 2025)
            throw invalid_argument("Invalid birth year");
        birthYear = y;
    }

    string to_string() const {
        return name + " (" + std::to_string(birthYear) + ")";
    }
};
