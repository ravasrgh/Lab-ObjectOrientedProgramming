#include "WeaponInventory.hpp"

void WeaponInventory::add(const string &id, const string &name, const string &type, int damage, int rarity) {
    weapons.push_back(Weapon(id, name, type, damage, rarity));
}

bool WeaponInventory::remove(const string &id) {
    auto it = std::find_if(weapons.begin(), weapons.end(), [&](const Weapon &w) { return w.id == id; });
    if (it == weapons.end()) return false;
    weapons.erase(it);
    return true;
}

const Weapon *WeaponInventory::find(const string &id) const {
    auto it = std::find_if(weapons.begin(), weapons.end(), [&](const Weapon &w) { return w.id == id; });
    if (it == weapons.end()) return nullptr;
    return &(*it);
}

void WeaponInventory::update(const string &id, const string &name, const string &type, int damage, int rarity) {
    auto it = std::find_if(weapons.begin(), weapons.end(), [&](Weapon &w) { return w.id == id; });
    if (it != weapons.end()) {
        it->name = name;
        it->type = type;
        it->damage = damage;
        it->rarity = rarity;
    }
}

void WeaponInventory::sort() {
    std::sort(weapons.begin(), weapons.end(), [](const Weapon &a, const Weapon &b) {
        if (a.rarity != b.rarity) return a.rarity > b.rarity;
        if (a.damage != b.damage) return a.damage > b.damage;
        return a.id < b.id;
    });
}

long long WeaponInventory::totalDamage(const string &type) const {
    return std::accumulate(weapons.begin(), weapons.end(), 0LL, [&](long long sum, const Weapon &w) {
        return w.type == type ? sum + w.damage : sum;
    });
}

int WeaponInventory::countByRarity(int minRarity) const {
    return std::count_if(weapons.begin(), weapons.end(), [&](const Weapon &w) { return w.rarity >= minRarity; });
}

void WeaponInventory::printByType(const string &type) const {
    bool found = false;
    for (auto it = weapons.begin(); it != weapons.end(); ++it) {
        if (it->type == type) {
            cout << it->id << "|" << it->name << "|" << it->type << "|" << it->damage << "|" << it->rarity << "\n";
            found = true;
        }
    }
    if (!found) cout << "EMPTY\n";
}

void WeaponInventory::print() const {
    if (weapons.empty()) {
        cout << "EMPTY\n";
        return;
    }
    for (auto it = weapons.begin(); it != weapons.end(); ++it) {
        cout << it->id << "|" << it->name << "|" << it->type << "|" << it->damage << "|" << it->rarity << "\n";
    }
}

int WeaponInventory::upgradeAll(const string &type, int bonusDamage) {
    int count = 0;
    std::for_each(weapons.begin(), weapons.end(), [&](Weapon &w) {
        if (w.type == type) {
            w.damage += bonusDamage;
            count++;
        }
    });
    return count;
}
