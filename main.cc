#include "fuzzy.h"

int main() {
  fuzzy f;

  f.fuzzification(1,-0.5); //test for fuzzification
  f.inference();


  return 0;
}
