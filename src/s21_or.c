#include "s21_decimal.h"

// returns x | y
s21_big_decimal s21_big_decimal_or(s21_big_decimal x, s21_big_decimal y) {
  for (int i = 0; i < 7; i++) {
    x.bits[i] = x.bits[i] | y.bits[i];
  }
  return x;
}