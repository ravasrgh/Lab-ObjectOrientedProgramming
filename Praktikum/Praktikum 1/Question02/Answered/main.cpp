#include <iostream>
#include "Paper.hpp"

using namespace std;

int main() {
  Paper* a = new Paper('A');
  Paper b('B');
  Paper c('C');
  Paper c2(c);
  a->fold();
  b.fold();
  c.fold();
  c.glue();
  delete a;
  c.setName('X');
  c2.fold();
  c2.glue();

  return 0;
}