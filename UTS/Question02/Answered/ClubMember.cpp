#include "ClubMember.hpp"
#include "Formatter.hpp"
#include <iostream>

ClubMember::ClubMember(std::string n, int a, std::string c) :
name(n), age(a), contractEnd(c)
    // TODO: constructor
{}

ClubMember::~ClubMember() {
    // TODO: log destruction menggunakan Formatter::log
    Formatter::log("~ClubMember",name,"contract record cleared.");
}
