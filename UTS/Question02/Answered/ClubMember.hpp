#pragma once
#include <string>

class ClubMember {
protected:
    // TODO: deklarasikan atribut kelas (name, age, contractEnd)
    std::string name;
    int age;
    std::string contractEnd;

public:
    // TODO: deklarasikan constructor, methods getProfile(), calculateWage(), work(), serta destructor
    ClubMember(std::string, int, std::string);
    virtual ~ClubMember();
    virtual std::string getProfile() = 0;
    virtual double calculateWage() = 0;
    virtual void work() = 0;

};
