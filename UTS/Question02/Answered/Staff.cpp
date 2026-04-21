#include "Staff.hpp"
#include "Formatter.hpp"

Staff::Staff(std::string n, int a, std::string c, std::string l, std::string d)
    // TODO: Constructor
    : ClubMember(n,a,c), coachingLicense(l), department(d)
{
}

double Staff::calculateWage() const {
    // TODO: return fixed wage, yaitu 50000.
    return 50000;
}

Staff::~Staff() {
    // TODO: log destruction menggunakan Formatter::log
    Formatter::log("~Staff",name,"session record freed.");
}
