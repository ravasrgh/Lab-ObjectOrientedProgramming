#include "Player.hpp"
#include "Formatter.hpp"

Player::Player(std::string name, int age, std::string contract, std::string posi, int stamina, double rate)
    // TODO: constructor
    : ClubMember(name, age, contract), position(posi), stamina(stamina), rating(rate)
{
}

double Player::calculateWage() const {
    // TODO: return wage player dengan rumus rating * 10000.0
    return rating * 10000.0;
}

Player::~Player() {
    // TODO: log destruction menggunakan Formatter::log
    Formatter::log("~Player",name,"training log freed.");
}
