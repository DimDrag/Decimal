#include "s21_decimal.h"

// converts decimal to big decimal
s21_big_decimal s21_from_decimal_to_big_decimal(s21_decimal x) {
  s21_big_decimal res = NULL_BIG_DECIMAL;
  for (int i = 0; i < 3; i++) {
    res.bits[i] = x.bits[i];
  }
  res.bits[7] = x.bits[3];
  return res;
}