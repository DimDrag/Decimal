#include "s21_decimal.h"

// returns x == y
int s21_is_equal(s21_decimal x, s21_decimal y) {
  x = normalize(x);
  y = normalize(y);
  bool res = true;
  for (int i = 0; i < 4; i++) {
    if (x.bits[i] != y.bits[i]) res = false;
  }
  return res;
}

// returns x == y
int s21_big_is_equal(s21_big_decimal x, s21_big_decimal y) {
  x = normalize(x);
  y = normalize(y);
  bool res = true;
  for (int i = 0; i < 8; i++) {
    if (x.bits[i] != y.bits[i]) res = false;
  }
  return res;
}