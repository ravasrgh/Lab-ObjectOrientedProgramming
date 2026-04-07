#ifndef WEAPON_INVENTORY_HPP
#define WEAPON_INVENTORY_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct Weapon {
  string id;
  string name;
  string type;
  int damage;
  int rarity;

  Weapon(const string &id, const string &name, const string &type, int damage, int rarity)
      : id(id), name(name), type(type), damage(damage), rarity(rarity) {}
};

class WeaponInventory {
private:
  vector<Weapon> weapons;

public:
  void add(const string &id, const string &name, const string &type, int damage, int rarity);
  bool remove(const string &id);
  const Weapon *find(const string &id) const;
  void update(const string &id, const string &name, const string &type, int damage, int rarity);
  void sort();
  long long totalDamage(const string &type) const;
  int countByRarity(int minRarity) const;
  void printByType(const string &type) const;
  void print() const;
  int upgradeAll(const string &type, int bonusDamage);
};

#endif
