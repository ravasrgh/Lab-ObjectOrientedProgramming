#include <iostream>
#include "Penganan.hpp"

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan(): keik(0), panekuk(0) {}

Penganan::Penganan(int keik, int panekuk): keik(keik), panekuk(panekuk) {}

int Penganan::GetKeik() { return keik; }

int Penganan::GetPanekuk() { return panekuk; }

void Penganan::SetKeik(int keik) { this->keik = keik; }

void Penganan::SetPanekuk(int panekuk) { this->panekuk = panekuk; }

Penganan operator+ (const Penganan& p1, const Penganan& p2) {
  Penganan::n_rumah++;
  return Penganan(p1.keik + p2.keik, p1.panekuk + p2.panekuk);
}

Penganan operator- (const Penganan& p1, const Penganan& p2) {
  int jualKeik = (p1.keik >= p2.keik) ? p2.keik : p1.keik;
  int jualPanekuk = (p1.panekuk >= p2.panekuk) ? p2.panekuk : p1.panekuk;

  Penganan::uang += jualKeik * 51 + jualPanekuk * 37;

  return Penganan(p1.keik - jualKeik, p1.panekuk - jualPanekuk);
}

Penganan operator^ (const Penganan& p, const int n) {
  int sisaK = (p.keik - n < 0) ? 0 : (p.keik - n);
  int sisaP = (p.panekuk - n < 0) ? 0 : (p.panekuk - n);

  int defK = (p.keik - n < 0) ? (p.keik - n) : 0;
  int defP = (p.panekuk - n < 0) ? (p.panekuk - n) : 0;

  Penganan::uang += (defK * 51 + defP * 37);

  return Penganan(sisaK, sisaP);
}

Penganan operator^ (const int n, const Penganan& p) {
  return p ^ n;
}

int Penganan::JumlahUang() { return uang; }

int Penganan::HitungNRumah() { return n_rumah; }

void Penganan::Print() { std::cout << keik << "keik-" << panekuk << "panekuk\n"; }

