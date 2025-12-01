#pragma once
#include <string>
using namespace std;

class Member {
    string name;
    string memberId;
    int yearJoined;

public:
    Member();
    Member(const string& n, const string& id, int y);

    const string& getId() const { return memberId; }

    string to_string() const;
};
