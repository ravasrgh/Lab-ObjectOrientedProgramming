#pragma once
#include "ClubMember.hpp"
#include <string>

class Player : // TODO: tentukan mode inheritance yang benar
virtual public ClubMember {
protected:
    // TODO: deklarasikan atribut kelas (position, stamina, rating)
    std::string position;
    int stamina;
    double rating;
public:
    // TODO: deklarasikan constructor, method calculateWage() dan pure virtual calculateRating() serta destructor
    Player(std::string, int, std::string, std::string, int, double);
    double calculateWage() const;
    virtual double calculateRating() = 0;
    ~Player();
};
