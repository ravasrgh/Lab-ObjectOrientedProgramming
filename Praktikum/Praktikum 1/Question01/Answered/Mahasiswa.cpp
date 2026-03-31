#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


class Mahasiswa {
  private:
    string name;
    float ipk;
    int total_sks;
    string nim = "135";
    static int counter;

  public:
    Mahasiswa() {
      name = "NPC";
      ipk = 0;
      total_sks = 0;
      nim = nim + to_string(counter);
      counter++;
    }
    
    Mahasiswa(string name) {
      this->name = name;
      ipk = 0;
      total_sks = 0;
      nim = nim + to_string(counter);
      counter++;
    }

    void tambahNilai(float nilai, int sksBaru) {
      this->ipk = (this->ipk * total_sks + nilai * sksBaru) / (total_sks + sksBaru);
      total_sks += sksBaru;
    }

    void info() {
      cout << "INFORMASI MAHASISWA\n";
      cout << "Nama: " << name << "\n";
      cout << "NIM: " << nim <<"\n";
      printf("IPK: %.2f\n", ipk);
      cout << "SKS: " << total_sks << "\n";
    }
};

int Mahasiswa::counter = 0;