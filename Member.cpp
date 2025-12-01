#include "Member.h"
#include <stdexcept>

Member::Member() : name("Unknown"), memberId("NONE"), yearJoined(2000) {}

Member::Member(const string& n, const string& id, int y)
    : name(n), memberId(id), yearJoined(y) 
{
    if (id.empty()) throw invalid_argument("Member ID cannot be empty");
}

string Member::to_string() const {
    return name + " | " + memberId + " | Joined: " + std::to_string(yearJoined);
}
