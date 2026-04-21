#ifndef SAFE_BOX_HPP
#define SAFE_BOX_HPP

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include "SafeBoxException.hpp"

using namespace std;

// Template class SafeBox<T>:
// Menyimpan elemen bertipe T secara LIFO dengan kapasitas terbatas.
template<typename T>
class SafeBox {
private:
    int maxCapacity;
    function<bool(const T&)> val;
    vector<T> items;
public:
    // Inisialisasi box dengan kapasitas maksimum dan validator opsional.
    SafeBox(int capacity, function<bool(const T&)> validator = nullptr)
        : maxCapacity(capacity), val(validator) {}

    // Menyimpan item ke dalam box.
    void store(const T& item) {
        if (val != nullptr) {
            if (!val(item)) {
                throw InvalidItemException<T>(item);
            }
        }
        if ((int)items.size() >= maxCapacity) {
            throw BoxFullException(maxCapacity);
        }
        items.push_back(item);
    }

    // Mengambil dan menghapus item teratas (LIFO).
    T retrieve() {
        if (items.empty()) {
            throw BoxEmptyException();
        }
        T top = items.back();
        items.pop_back();
        return top;
    }

    // Melihat item teratas tanpa menghapusnya.
    T peek() const {
        if (items.empty()) {
            throw BoxEmptyException();
        }
        return items.back();
    }

    // Membalik urutan semua elemen dalam box.
    void reverse() {
        if (items.empty()) {
            throw BoxEmptyException();
        }
        std::reverse(items.begin(), items.end());
    }

    // Mengembalikan jumlah item saat ini.
    int size() const {
        return (int)items.size();
    }

    // Mengembalikan kapasitas maksimum box.
    int capacity() const {
        return maxCapacity;
    }

    // Mengembalikan true jika box kosong.
    bool isEmpty() const {
        return items.empty();
    }

    // Mencetak isi box dari bawah ke atas: [item_bawah, ..., item_atas]
    friend ostream& operator<<(ostream& os, const SafeBox<T>& box) {
        os << "[";
        for (int i = 0; i < (int)box.items.size(); ++i) {
            os << box.items[i];
            if (i < (int)box.items.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

// Template function safeMerge:
// Memindahkan item dari src ke dst satu per satu (urutan LIFO).
template<typename T>
int safeMerge(SafeBox<T>& src, SafeBox<T>& dst) {
    int moved = 0;
    while (!src.isEmpty()) {
        try {
            dst.store(src.peek());
            src.retrieve();
            moved++;
        } catch (const BoxFullException& e) {
            break;
        }
    }
    return moved;
}

#endif
