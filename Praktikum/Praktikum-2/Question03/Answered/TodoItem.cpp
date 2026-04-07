#include "TodoItem.hpp"

TodoItem::TodoItem(const std::string &name) : Activity(name) { isDone = false; }

TodoItem::~TodoItem() { cout << "Menghapus TodoItem " << name << "\n"; }

int TodoItem::complete() { 
    if (!isDone) {
        isDone = true;
        return 10;
    } else {
        return 0;
    }
}

string TodoItem::getStatus() const {
    if (isDone) {
        return "[TODO] " + name + " - Selesai";
    } else {
        return "[TODO] " + name + " - Belum";
    }
}
