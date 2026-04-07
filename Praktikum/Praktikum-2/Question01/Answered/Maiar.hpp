#pragma once
#include "Creature.hpp"
#include <iostream>

class Maiar : protected Creature {
protected:
    int power;

public:
    Maiar(const string& name, int hp, int power);
    ~Maiar();

    void describe() const;
    int getPower() const;
};