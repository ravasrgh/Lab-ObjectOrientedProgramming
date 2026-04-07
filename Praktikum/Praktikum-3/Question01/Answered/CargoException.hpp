#ifndef CARGO_EXCEPTION_HPP
#define CARGO_EXCEPTION_HPP

#include <exception>
#include <string>
using namespace std;

// TODO Implementasikan CargoException (Base)
// CargoException inherit std::exception
// Member: errorCode (int), errorMessage (string).
// Sediakan Constructor, getter, dan override what().
// override what() return errorMessage tapi dalam bentuk C-string (char *)
class CargoException : exception{
private:
    int errorCode;
    string errorMessage;

public:
    CargoException(int code, string message) : errorCode(code), errorMessage(message) {}
    int getErrorCode() const { return errorCode; }
    string getErrorMessage() const { return errorMessage; }
    const char* what() const noexcept {return errorMessage.c_str();}
};

// TODO Implementasikan CargoFullException (errorCode = 1, errorMessage = "Cargo is full!")
class CargoFullException : public CargoException {
public:
    CargoFullException() : CargoException(1, "Cargo is full!") {}
};
// TODO Implementasikan CargoEmptyException (errorCode = 2, errorMessage = "Cargo is empty!")
class CargoEmptyException : public CargoException {
public:
    CargoEmptyException() : CargoException(2, "Cargo is empty!") {}
};
// TODO Implementasikan ItemNotFoundException (errorCode = 3, errorMessage = "Item not found!")
class ItemNotFoundException : public CargoException {
public:
    ItemNotFoundException() : CargoException(3, "Item not found!") {}
};
// TODO Implementasikan NotEnoughItemsException (errorCode = 4, errorMessage = "Not enough items in cargo!")
class NotEnoughItemsException : public CargoException {
public:
    NotEnoughItemsException() : CargoException(4, "Not enough items in cargo!") {}
};
// TODO Implementasikan TransferFailedException (errorCode = 5, errorMessage = "Transfer failed due to destination capacity!")
class TransferFailedException : public CargoException {
public:
    TransferFailedException() : CargoException(5, "Transfer failed due to destination capacity!") {}
};

#endif
