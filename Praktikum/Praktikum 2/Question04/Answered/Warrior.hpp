#include "Character.hpp"

class Warrior : virtual public Character {
private:
  int strength;

public:
  Warrior(string characterId, string name, int hp, int level, int strength);
  ~Warrior();

  void attack() const;
  int getStrength() const;
};