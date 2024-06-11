#include "s21_decimal.h"

// shifts mantissa to the left
s21_decimal s21_shift_decimal_left(s21_decimal x, unsigned int shift) {
  for (unsigned int i = 0; i < shift; i++) {
    for (int bit = 2; bit > 0; bit--) {
      x.bits[bit] <<= 1;
      x.bits[bit] |= (x.bits[bit - 1] & (1 << 31)) >> 31;
    }
    x.bits[0] <<= 1;
  }
  return x;
}

s21_big_decimal s21_shift_big_decimal_left(s21_big_decimal x,
                                           unsigned int shift) {
  for (unsigned int i = 0; i < shift; i++) {
    for (int bit = 6; bit > 0; bit--) {
      x.bits[bit] <<= 1;
      x.bits[bit] |= (x.bits[bit - 1] & (1 << 31)) >> 31;
    }
    x.bits[0] <<= 1;
  }
  return x;
}