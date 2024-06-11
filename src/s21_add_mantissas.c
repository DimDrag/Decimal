#include "s21_decimal.h"

// adds up the mantissas of decimals (bit[3] of result doesn't change)
// returns 1 if error
int s21_add_decimal_mantissas(s21_decimal x, s21_decimal y,
                              s21_decimal* result) {
  int excess = 0;
  for (int i = 0; i < 3; i++) {
    uint64_t buff = (uint64_t)x.bits[i] + y.bits[i] + excess;
    if (buff != (uint32_t)buff) {
      result->bits[i] = buff - ((uint64_t)1 << 32);
      excess = 1;
    } else {
      result->bits[i] = buff;
      excess = 0;
    }
  }
  return excess;
}

// adds up the mantissas of decimals (bit[7] of result doesn't change)
// returns 1 if error
int s21_add_big_decimal_mantissas(s21_big_decimal x, s21_big_decimal y,
                                  s21_big_decimal* result) {
  int excess = 0;
  for (int i = 0; i < 7; i++) {
    uint64_t buff = (uint64_t)x.bits[i] + y.bits[i] + excess;
    if (buff != (uint32_t)buff) {
      result->bits[i] = buff - ((uint64_t)1 << 32);
      excess = 1;
    } else {
      result->bits[i] = buff;
      excess = 0;
    }
  }
  return excess;
}