#pragma once
#include "Maiar.hpp"
#include <iostream>

class Wizard : private Maiar {
protected:
    string staffName;

public:
    Wizard(const string& name, int hp, int power, string staffname);
    ~Wizard();

    void describe() const;
    void cast() const;
};