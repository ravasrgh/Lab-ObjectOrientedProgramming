#include "Warrior.hpp"

Warrior::Warrior(string characterId, string name, int hp, int level, int strength) :
Character(characterId, name, hp, level), strength(strength) {
  cout << "[CREATE] Warrior " << name << " with " << getStrength() << " str ready\n";
}

Warrior::~Warrior() {
  cout << "[DELETE] Warrior " << name << " destroyed\n";
}

void Warrior::attack() const {
  cout << "[ATTACK] " << name << " attacks with " << getStrength() << " strength\n";
}

int Warrior::getStrength() const {
  return strength;
}

