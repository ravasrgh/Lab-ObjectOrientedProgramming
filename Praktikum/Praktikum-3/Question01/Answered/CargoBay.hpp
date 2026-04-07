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
    // TODO Constructor & Destructor
    // Constructor: inisialisasi capacity, size = 0, alokasi array arr.
    // Destructor: Dealokasi array arr.
    CargoBay(int cap);
    ~CargoBay();

    // TODO Push & Pop (Standard)
    // push: Lempar CargoFullException jika size >= capacity. Taruh item ke index terakhir array
    // pop: Lempar CargoEmptyException jika size <= 0. Return item terakhir (LIFO) dan update size.
    void push(Item<T> item);
    Item<T> pop();

        // TODO extractItem
    // Cari item PERTAMA (dimulai dari index 0 hingga size-1)
    // yang nilai `data`-nya SAMA DENGAN `targetData`.
    // Jika ketemu:
    //     - Return Item tersebut.
    //     - Hapus Item tersebut dari array,
    //       lalu geser seluruh Item di kanannya ke kiri agar array tidak bolong.
    //     - Update size.
    // Jika tidak ketemu, lempar ItemNotFoundException.
    Item<T> extractItem(T targetData);

 // TODO forge
    // Menempa (Menggabungkan) dua Item teratas menjadi satu Item baru.
    // Cek apakah size < 2. Jika ya, lempar NotEnoughItemsException.
    // Jika aman, keluarkan (pop) item pertama dan item kedua.
    // Buatlah data baru hasil penjumlahan berurutan: `baseData` + data Top 1 + data Top 2.
    //   (Contoh: Jika baseData = "X", Top 1 = "Y", Top 2 = "Z", maka data baru = "XYZ").
    // Dipastikan tipe data T support operator+
    // Buatlah durability baru: rata-rata dari durability item pertama dan kedua (integer division).
    // Buat objek Item baru dengan data & durability baru tersebut, lalu push() ke CargoBay.
    void forge(T baseData);

    // TODO transferTo
    // Pindahkan sejumlah `count` item dari atas cargo `this` ke cargo `other`.
    // PROSES TRANSFER dilakukan satu per satu (LIFO).
    // Perhatikan bahwa urutan item akan terbalik.
    // Jika, size < count, lempar NotEnoughItemsException
    // PENANGANAN EXCEPTION:
    //    - Jika other ternyata penuh di tengah jalan (melempar CargoFullException),
    //      TANGKAP error tersebut dengan try-catch!
    //    - Kembalikan 1 item yang gagal masuk itu ke cargo `this`.
    //    - Lempar TransferFailedException ke luar fungsi untuk memberitahu bahwa transfer terhenti.
    void transferTo(CargoBay<T>& other, int count);
};


// TODO Constructor & Destructor
// Constructor: inisialisasi capacity, size = 0, alokasi array arr.
// Destructor: Dealokasi array arr.
template <class T>
CargoBay<T>::CargoBay(int cap) : capacity(cap) {}

template <class T>
CargoBay<T>::~CargoBay() {delete arr;}

// TODO Push & Pop (Standard)
// push: Lempar CargoFullException jika size >= capacity. Taruh item ke index terakhir array
// pop: Lempar CargoEmptyException jika size <= 0. Return item terakhir (LIFO) dan update size.
template <class T>
void CargoBay<T>::push(Item<T> item) {
    if (size >= capacity) {
        throw CargoFullException();
    }
    arr[size] = item;
    size++;
}

template <class T>
Item<T> CargoBay<T>::pop() {
    if (size <= 0) {
        throw CargoEmptyException();
    }
    Item<T> lastItem = arr[size];
    size--;
    return lastItem;
}

// TODO extractItem
// Cari item PERTAMA (dimulai dari index 0 hingga size-1)
// yang nilai `data`-nya SAMA DENGAN `targetData`.
// Jika ketemu:
//     - Return Item tersebut.
//     - Hapus Item tersebut dari array,
//       lalu geser seluruh Item di kanannya ke kiri agar array tidak bolong.
//     - Update size.
// Jika tidak ketemu, lempar ItemNotFoundException.
template <class T>
Item<T> CargoBay<T>::extractItem(T targetData) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getData() == targetData)
        {
            Item<T> returnItem = arr[i];
            for (int j = i; j != size; j++) {
                arr[j] = arr[j+1];
            }
            size--;
            return (returnItem);
        }
    }
    throw ItemNotFoundException();
}
 // TODO forge
    // Menempa (Menggabungkan) dua Item teratas menjadi satu Item baru.
    // Cek apakah size < 2. Jika ya, lempar NotEnoughItemsException.
    // Jika aman, keluarkan (pop) item pertama dan item kedua.
    // Buatlah data baru hasil penjumlahan berurutan: `baseData` + data Top 1 + data Top 2.
    //   (Contoh: Jika baseData = "X", Top 1 = "Y", Top 2 = "Z", maka data baru = "XYZ").
    // Dipastikan tipe data T support operator+
    // Buatlah durability baru: rata-rata dari durability item pertama dan kedua (integer division).
    // Buat objek Item baru dengan data & durability baru tersebut, lalu push() ke CargoBay.
template <class T>
void CargoBay<T>::forge(T baseData) {
    if (size < 2)
    {
        throw NotEnoughItemsException();
    }
    Item<T> item1 = pop();
    Item<T> item2 = pop();
    Item<T> newItem{baseData + item1.getData() + item2.getData(), (item1.getDurability() + item2.getDurability()) / 2};
    push(newItem);
}

// TODO transferTo
    // Pindahkan sejumlah `count` item dari atas cargo `this` ke cargo `other`.
    // PROSES TRANSFER dilakukan satu per satu (LIFO).
    // Perhatikan bahwa urutan item akan terbalik.
    // Jika, size < count, lempar NotEnoughItemsException
    // PENANGANAN EXCEPTION:
    //    - Jika other ternyata penuh di tengah jalan (melempar CargoFullException),
    //      TANGKAP error tersebut dengan try-catch!
    //    - Kembalikan 1 item yang gagal masuk itu ke cargo `this`.
    //    - Lempar TransferFailedException ke luar fungsi untuk memberitahu bahwa transfer terhenti.
template <class T>
void CargoBay<T>::transferTo(CargoBay<T>& other, int count) {
    if (size < count){
        throw NotEnoughItemsException();
    }
    Item<T> item;
    try {
        for (int i = 0; i < count; i++)
        {
            item = pop();
            other.push(item);
        }
    } catch (CargoException& e) {
        push(item);
        throw TransferFailedException();
    }
}

#endif
