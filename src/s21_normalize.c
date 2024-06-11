#include "s21_decimal.h"

// normalize decimal number
s21_decimal s21_normalize_decimal(s21_decimal x) {
  int check = 1;
  for (int i = 0; i < 3; i++) {
    check *= x.bits[i] == 0;
  }
  if (check)
    x = NULL_DECIMAL;
  else
    while (get_rem_10(x) == 0 && get_exponent(x) != 0) {
      x = div_by_10(x);
    }
  return x;
}

// normalize big decimal number
s21_big_decimal s21_normalize_big_decimal(s21_big_decimal x) {
  int check = 1;
  for (int i = 0; i < 7; i++) {
    check *= x.bits[i] == 0;
  }
  if (check)
    x = NULL_BIG_DECIMAL;
  else
    while (get_rem_10(x) == 0 && get_exponent(x) != 0) {
      x = div_by_10(x);
    }
  return x;
}