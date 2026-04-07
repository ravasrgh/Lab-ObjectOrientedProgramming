#pragma once
#include "Creature.hpp"
#include <iostream>

class Elf : public Creature {
protected:
    int grace;

public:
    Elf(const string& name, int hp, int grace);
    ~Elf();

    void describe() const;
    int getGrace() const;
};