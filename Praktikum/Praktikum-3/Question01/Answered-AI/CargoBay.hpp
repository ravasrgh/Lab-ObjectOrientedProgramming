#ifndef CARGO_BAY_HPP
#define CARGO_BAY_HPP

#include "Item.hpp"
#include "CargoException.hpp"

template <class T>
class CargoBay {
private:
    Item<T>* arr;
    int capacity;
    int size;

public:
    CargoBay(int cap);
    ~CargoBay();
    void push(Item<T> item);
    Item<T> pop();
    Item<T> extractItem(T targetData);
    void forge(T baseData);
    void transferTo(CargoBay<T>& other, int count);
};

template <class T>
CargoBay<T>::CargoBay(int cap) {
    this->capacity = cap;
    this->size = 0;
    this->arr = new Item<T>[cap];
}

template <class T>
CargoBay<T>::~CargoBay() {
    delete[] arr;
}

template <class T>
void CargoBay<T>::push(Item<T> item) {
    if (size >= capacity) throw CargoFullException();
    arr[size++] = item;
}

template <class T>
Item<T> CargoBay<T>::pop() {
    if (size <= 0) throw CargoEmptyException();
    return arr[--size];
}

template <class T>
Item<T> CargoBay<T>::extractItem(T targetData) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getData() == targetData) {
            Item<T> found = arr[i];
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            return found;
        }
    }
    throw ItemNotFoundException();
}

template <class T>
void CargoBay<T>::forge(T baseData) {
    if (size < 2) throw NotEnoughItemsException();
    Item<T> top1 = pop();
    Item<T> top2 = pop();
    T newData = baseData + top1.getData() + top2.getData();
    int newDurability = (top1.getDurability() + top2.getDurability()) / 2;
    push(Item<T>(newData, newDurability));
}

template <class T>
void CargoBay<T>::transferTo(CargoBay<T>& other, int count) {
    if (size < count) throw NotEnoughItemsException();
    for (int i = 0; i < count; i++) {
        Item<T> item = pop();
        try {
            other.push(item);
        } catch (CargoFullException&) {
            push(item);
            throw TransferFailedException();
        }
    }
}

#endif
