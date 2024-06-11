#include "s21_decimal.h"

// divides decimal's mantissa by 10
s21_decimal s21_div_decimal_by_10(s21_decimal x) {
  uint64_t prev_rem = 0;
  for (int i = 2; i >= 0; i--) {
    uint64_t rem = (x.bits[i] + prev_rem) % 10 << 32;
    x.bits[i] = (x.bits[i] + prev_rem) / 10;
    prev_rem = rem;
  }
  set_exponent(&x, get_exponent(x) - 1);
  return x;
}

// divides big decimal's mantissa by 10
s21_big_decimal s21_div_big_decimal_by_10(s21_big_decimal x) {
  uint64_t prev_rem = 0;
  for (int i = 6; i >= 0; i--) {
    uint64_t rem = (x.bits[i] + prev_rem) % 10 << 32;
    x.bits[i] = (x.bits[i] + prev_rem) / 10;
    prev_rem = rem;
  }
  set_exponent(&x, get_exponent(x) - 1);
  return x;
}