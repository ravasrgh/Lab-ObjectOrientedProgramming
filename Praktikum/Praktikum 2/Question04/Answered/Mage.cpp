#include "Mage.hpp"

Mage::Mage(string characterId, string name, int hp, int level, int mana) :
Character(characterId, name, hp, level), mana(mana) {
  cout << "[CREATE] Mage " << name << " with " << getMana() << " mana ready\n";
}

Mage::~Mage() {
  cout << "[DELETE] Mage " << name << " destroyed\n";
}

void Mage::castSpell() const {
  cout << "[CAST] " << name << " casts a spell using " << getMana() << " mana\n";
}

int Mage::getMana() const {
  return mana;
}

