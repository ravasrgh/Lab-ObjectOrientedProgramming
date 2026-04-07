#pragma once
#include "Elf.hpp"
#include <iostream>

class Ranger : public Elf {
protected:
    int arrows;

public:
    Ranger(const string& name, int hp, int grace, int arrows);
    ~Ranger();

    void describe() const;
    void shoot() ;
};