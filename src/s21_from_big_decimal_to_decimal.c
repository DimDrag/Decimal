#include "s21_decimal.h"

// converts big decimal to decimal
s21_decimal s21_from_big_decimal_to_decimal(s21_big_decimal x) {
  s21_decimal res = NULL_DECIMAL;
  for (int i = 0; i < 3; i++) {
    res.bits[i] = x.bits[i];
  }
  res.bits[3] = x.bits[7];
  return res;
}