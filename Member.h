#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Member {
    string name;
    string memberId;
    int yearJoined;

public:
    Member() : name("Unknown"), memberId("NONE"), yearJoined(2000) {}

    Member(const string& n, const string& id, int y)
        : name(n), memberId(id), yearJoined(y)
    {
        if (id.empty()) throw invalid_argument("Member ID cannot be empty");
    }

    const string& getId() const { return memberId; }

    string to_string() const {
        return name + " | " + memberId + " | Joined: " + std::to_string(yearJoined);
    }
};
