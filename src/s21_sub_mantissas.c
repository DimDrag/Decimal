#include "s21_decimal.h"

// subtracts mantissas of decimals (bit[7] of result doesn't change)
void s21_sub_big_decimal_mantissas(s21_big_decimal x, s21_big_decimal y,
                                   s21_big_decimal* result) {
  int flaw = 0;
  for (int i = 0; i < 7; i++) {
    uint64_t buff = (uint64_t)x.bits[i] - y.bits[i] - flaw;
    if (buff != (uint32_t)buff) {
      result->bits[i] = buff + ((uint64_t)1 << 32);
      flaw = 1;
    } else {
      result->bits[i] = buff;
      flaw = 0;
    }
  }
}