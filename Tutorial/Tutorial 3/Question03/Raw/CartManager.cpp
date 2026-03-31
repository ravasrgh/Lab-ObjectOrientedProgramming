#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct GameEntry {
    string title;
    float price;

    GameEntry(string t, float p) {
        title = t;
        price = p;
    }
};

class CartManager {
private:
    // TODO: Deklarasikan vector yang dibutuhkan

public:
    void addToCart(string title, float price) {
        // TODO: Menambahkan game ke akhir keranjang. Judul yang sama boleh muncul lebih dari sekali.
    }

    bool removeFromCart(string title) {
        // TODO: Menghapus kemunculan pertama game dengan judul tersebut. Kembalikan true jika berhasil, false jika tidak ditemukan. Urutan harus tetap terjaga.
        return false;
    }

    void checkout() {
        // TODO: Memindahkan semua game dari keranjang ke library, lalu mengosongkan keranjang. Jika keranjang kosong, tidak melakukan apa-apa.
    }

    float cartTotal() {
        // TODO: Mengembalikan total harga semua item di keranjang.
        return 0.0f;
    }

    float applyDiscount(float percent) {
        // TODO: Menerapkan diskon (misalnya 10.0 = 10%) ke semua item dalam keranjang secara langsung (price game dalam keranjang berubah). Mengembalikan total baru. Jika keranjang kosong, kembalikan 0.0.
        return 0.0f;
    }

    int countInCart(string title) {
        // TODO: Menghitung berapa kali game dengan judul tersebut muncul di keranjang.
        return 0;
    }

    void printCart() {
        // TODO: sesuaikan nama variablenya
        if (cart.size() == 0) {
            cout << "Cart is empty." << endl;
            return;
        }
        for (int i = 0; i < cart.size(); i++) {
            cout << "[" << i << "] " << cart[i].title << " - $" << cart[i].price << endl;
        }
    }

    void printPurchased() {
        // TODO: sesuaikan nama variablenya
        if (purchased.size() == 0) {
            cout << "No purchases yet." << endl;
            return;
        }
        for (int i = 0; i < purchased.size(); i++) {
            cout << "[" << i << "] " << purchased[i].title << " - $" << purchased[i].price << endl;
        }
    }

    int totalPurchased() {
        // TODO: Mengembalikan jumlah total game yang ada di library.
        return 0;
    }
};

int main() {
    CartManager cm;
    int q;
    
    if (!(cin >> q)) return 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op == "ADD") {
            string title; float price;
            cin >> title >> price;
            cm.addToCart(title, price);
        } else if (op == "REMOVE") {
            string title; cin >> title;
            if (cm.removeFromCart(title))
                cout << "Removed: " << title << "\n";
            else
                cout << "Not found: " << title << "\n";
        } else if (op == "CHECKOUT") {
            cm.checkout();
        } else if (op == "TOTAL") {
            cout << "Cart total: $" << cm.cartTotal() << "\n";
        } else if (op == "DISCOUNT") {
            float pct; cin >> pct;
            cout << "After discount: $" << cm.applyDiscount(pct) << "\n";
        } else if (op == "COUNT") {
            string title; cin >> title;
            cout << title << ": " << cm.countInCart(title) << " in cart\n";
        } else if (op == "PRINT_CART") {
            cm.printCart();
        } else if (op == "PRINT_PURCHASED") {
            cm.printPurchased();
        } else if (op == "PURCHASED_COUNT") {
            cout << "Total purchased: " << cm.totalPurchased() << "\n";
        }
    }

    return 0;
}