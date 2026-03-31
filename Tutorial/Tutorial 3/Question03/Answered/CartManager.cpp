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
    vector<GameEntry> cart;
    vector<GameEntry> purchased;

public:
    void addToCart(string title, float price) {
        cart.push_back(GameEntry(title, price));
    }

    bool removeFromCart(string title) {
        for (int i = 0; i < cart.size(); i++) {
            if (cart[i].title == title) {
                cart.erase(cart.begin() + i);
                return true;
            }
        }
        return false;
    }

    void checkout() {
        if (!cart.empty()) {
            purchased.insert(purchased.end(), cart.begin(), cart.end());
            cart.clear();
        }
    }

    float cartTotal() {
        float total = 0.0f;
        for (int i = 0; i < cart.size(); i++) {
            total += cart[i].price;
        }
        return total;
    }

    float applyDiscount(float percent) {
        if (cart.empty()) return 0.0f;
        float total = 0.0f;
        for (int i = 0; i < cart.size(); i++) {
            cart[i].price -= cart[i].price * (percent / 100.0f);
            total += cart[i].price;
        }
        return total;
    }

    int countInCart(string title) {
        int count = 0;
        for (int i = 0; i < cart.size(); i++) {
            if (cart[i].title == title) {
                count++;
            }
        }
        return count;
    }

    void printCart() {
        if (cart.size() == 0) {
            cout << "Cart is empty." << endl;
            return;
        }
        for (int i = 0; i < cart.size(); i++) {
            cout << "[" << i << "] " << cart[i].title << " - $" << cart[i].price << endl;
        }
    }

    void printPurchased() {
        if (purchased.size() == 0) {
            cout << "No purchases yet." << endl;
            return;
        }
        for (int i = 0; i < purchased.size(); i++) {
            cout << "[" << i << "] " << purchased[i].title << " - $" << purchased[i].price << endl;
        }
    }

    int totalPurchased() {
        return purchased.size();
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