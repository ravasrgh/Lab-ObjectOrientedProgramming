#ifndef SAFE_BOX_EXCEPTION_HPP
#define SAFE_BOX_EXCEPTION_HPP

#include <exception>
#include <string>
#include <sstream>
using namespace std;

// Base class untuk semua exception SafeBox.
// Turunan dari std::exception override what() di setiap subclass.
class SafeBoxException : public exception {
public:
    virtual const char* what() const noexcept = 0;
};


class BoxFullException : public SafeBoxException {
private:
    int cap;
    string msg;
public:
    BoxFullException(int capacity) : cap(capacity) {
        ostringstream oss;
        oss << "Box penuh: kapasitas maks " << cap;
        msg = oss.str();
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};


class BoxEmptyException : public SafeBoxException {
public:
    const char* what() const noexcept override {
        return "Box kosong";
    }
};


// Template: item yang tidak valid dapat bertipe apa saja (int, string, dll.)
// Gunakan ostringstream untuk mengonversi T ke string di dalam what().
template<typename T>
class InvalidItemException : public SafeBoxException {
private:
    T item;
    string msg;
public:
    InvalidItemException(const T& item) : item(item) {
        ostringstream oss;
        oss << "Item tidak valid: " << item;
        msg = oss.str();
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

#endif
