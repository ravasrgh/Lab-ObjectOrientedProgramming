#pragma once
#include "Maiar.hpp"
#include <iostream>

class Balrog : public Maiar {
protected:
    string whipName;

public:
    Balrog(const string& name, int hp, int power, string whipName);
    ~Balrog();

    void describe() const;
    void rage() const;
};