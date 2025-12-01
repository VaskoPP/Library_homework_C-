#pragma once
#include <string>
using namespace std;

class Author {
    string name;
    int birthYear;

public:
    Author();
    Author(const string& name, int birthYear);

    const string& getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y);

    string to_string() const;
};

