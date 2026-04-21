#pragma once
#include "Player.hpp"
#include "Staff.hpp"
#include <string>

class PlayerCoach : public Player, public Staff// TODO: tentukan mode inheritance yang benar dan pastikan urutannya tepat
{
private:
    // TODO: deklarasikan atribut kelas (yearsAsPlayer, isCurrentlyPlaying)
    int yearsAsPlayer;
    bool isCurrentlyPlaying;

public:
    // TODO: deklarasikan constructor, methods work(), calculateRating(), getSpecialty(), calculateWage(), getProfile(), dan destructor
    PlayerCoach(std::string, int, std::string, std::string, int, double, std::string, int, bool);
    void work() const ;
    double calculateRating() const ;
    std::string getSpecialty() const ;
    double calculateWage() const;
    std::string getProfile() const ;
    ~PlayerCoach();
};

