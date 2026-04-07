#include "Character.hpp"

class Mage : virtual public Character {
private:
  int mana;

public:
  Mage(string characterId, string name, int hp, int level, int mana);
  ~Mage();

  void castSpell() const;
  int getMana() const;
};