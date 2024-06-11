#include "s21_decimal.h"

// set exponent of decimal number in base-10 form
void s21_set_decimal_exponent(s21_decimal* x, unsigned int exp) {
  x->bits[3] &= ~(((1 << 8) - 1) << 16);
  x->bits[3] |= exp << 16;
}

// set exponent of big decimal number in base-10 form
void s21_set_big_decimal_exponent(s21_big_decimal* x, unsigned int exp) {
  x->bits[7] &= ~(((1 << 8) - 1) << 16);
  x->bits[7] |= exp << 16;
}