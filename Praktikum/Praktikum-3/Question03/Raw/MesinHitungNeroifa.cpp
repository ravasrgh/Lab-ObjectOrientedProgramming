#include "MesinHitungNeroifa.hpp"
#include "MesinHitungException.hpp"

#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

MesinHitungNeroifa::MesinHitungNeroifa() {}

int MesinHitungNeroifa::hitung(const string& ekspresi) const {
    stack<int> st;
    stringstream ss(ekspresi);
    string token;

    while (ss >> token) {
        // TODO:
        // Jika token adalah operator (+, -, *, /),
        // lakukan operasi terhadap dua elemen teratas stack.
        // Jika jumlah operand tidak mencukupi, lempar exception yang sesuai.

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // TODO: cek apakah stack memiliki minimal 2 operand

            // TODO: ambil dua operand teratas dari stack
            int operand2;
            int operand1;

            // TODO: lakukan operasi sesuai token
            // Perhatikan bahwa pembagian dengan nol harus melempar exception
        } else {
            // TODO:
            // Anggap token sebagai kandidat bilangan bulat.
            // Cek apakah token valid:
            // - boleh berupa bilangan negatif
            // - selain itu semua karakter harus digit
            bool valid = true;
            int startIdx = 0;

            // TODO: tangani kasus bilangan negatif

            // TODO: cek apakah semua karakter yang relevan adalah digit

            if (!valid) {
                // TODO: lempar exception yang sesuai
            }

            // TODO: ubah token menjadi integer lalu push ke stack
        }
    }

    // TODO:
    // Setelah semua token diproses, stack harus berisi tepat satu elemen.
    // Jika tidak, lempar exception yang sesuai.

    // TODO: kembalikan hasil akhir
    return 0;
}