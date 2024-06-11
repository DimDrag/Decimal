#include "s21_decimal.h"

// shifts mantissa to the right
s21_decimal s21_shift_decimal_right(s21_decimal x, unsigned int shift) {
  for (unsigned int i = 0; i < shift; i++) {
    for (int bit = 0; bit < 2; bit++) {
      x.bits[bit] >>= 1;
      x.bits[bit] |= (x.bits[bit + 1] & 1) << 31;
    }
    x.bits[2] >>= 1;
  }
  return x;
}

s21_big_decimal s21_shift_big_decimal_right(s21_big_decimal x,
                                            unsigned int shift) {
  for (unsigned int i = 0; i < shift; i++) {
    for (int bit = 0; bit < 6; bit++) {
      x.bits[bit] >>= 1;
      x.bits[bit] |= (x.bits[bit + 1] & 1) << 31;
    }
    x.bits[6] >>= 1;
  }
  return x;
}