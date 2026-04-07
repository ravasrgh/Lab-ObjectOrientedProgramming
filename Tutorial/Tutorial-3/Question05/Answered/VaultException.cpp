#include "VaultException.hpp"

VaultException::VaultException(const std::string& msg) : message(msg) {}

const char* VaultException::what() const noexcept {
    return message.c_str();
}

EmptyVaultException::EmptyVaultException() : VaultException("Error: Vault kosong") {}

FullVaultException::FullVaultException(size_t cap) : VaultException("Error: Vault sudah penuh"), vaultCapacity(cap) {}

size_t FullVaultException::getCapacity() const {
    return vaultCapacity;
}

InvalidRelicException::InvalidRelicException(const std::string& name, const std::string& reason)
    : VaultException("Error: Nama relic tidak valid - " + reason), relicName(name) {}

std::string InvalidRelicException::getRelicName() const {
    return relicName;
}
