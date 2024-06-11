#include "s21_decimal.h"

void s21_set_decimal_sign(s21_decimal* x, int sign) {
  x->bits[3] = (sign) ? (x->bits[3] | (1 << 31)) : (x->bits[3] & ~(1 << 31));
}

void s21_set_big_decimal_sign(s21_big_decimal* x, int sign) {
  x->bits[7] = (sign) ? (x->bits[7] | (1 << 31)) : (x->bits[7] & ~(1 << 31));
}