#include "RelicVault.hpp"
#include "VaultException.hpp"
#include <cctype>

RelicVault::RelicVault(size_t capacity) : maxCapacity(capacity) {}

void RelicVault::push(const std::string& name) {
    if (name.length() < 3) {
        throw InvalidRelicException(name, "nama terlalu pendek");
    }
    for (char c : name) {
        if (std::isdigit(c)) {
            throw InvalidRelicException(name, "mengandung angka");
        }
    }
    if (vault.size() >= maxCapacity) {
        throw FullVaultException(maxCapacity);
    }
    vault.push_back(name);
}

std::string RelicVault::pop() {
    if (vault.empty()) {
        throw EmptyVaultException();
    }
    std::string topElement = vault.back();
    vault.pop_back();
    return topElement;
}

std::string RelicVault::top() const {
    if (vault.empty()) {
        throw EmptyVaultException();
    }
    return vault.back();
}

size_t RelicVault::size() const {
    return vault.size();
}

size_t RelicVault::capacity() const {
    return maxCapacity;
}

bool RelicVault::empty() const {
    return vault.empty();
}
