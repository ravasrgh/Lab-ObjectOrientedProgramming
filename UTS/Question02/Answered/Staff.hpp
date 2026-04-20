#pragma once
#include "ClubMember.hpp"
#include <string>

class Staff : // TODO: tentukan mode inheritance yang benar
virtual public ClubMember{
protected:
    // TODO: deklarasikan atribut kelas (coachingLicense, department)
    std::string coachingLicense;
    std::string department;
public:
    // TODO: deklarasikan constructor, methods calculateWage() dan pure virtual getSpeciality(), serta destructor 
    Staff(std::string, int, std::string, std::string, std::string);
    double calculateWage();
    virtual std::string getSpecialty() = 0;
    ~Staff();
};
