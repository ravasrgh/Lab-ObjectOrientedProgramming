#ifndef VAULT_EXCEPTION_HPP
#define VAULT_EXCEPTION_HPP

#include <exception>
#include <string>

class VaultException : public std::exception {
protected:
    std::string message;
public:
    VaultException(const std::string& msg);
    virtual const char* what() const noexcept override;
};

class EmptyVaultException : public VaultException {
public:
    EmptyVaultException();
};

class FullVaultException : public VaultException {
private:
    size_t vaultCapacity;
public:
    FullVaultException(size_t cap);
    size_t getCapacity() const;
};

class InvalidRelicException : public VaultException {
private:
    std::string relicName;
public:
    InvalidRelicException(const std::string& name, const std::string& reason);
    std::string getRelicName() const;
};

#endif
