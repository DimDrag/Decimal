#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  *dst = NULL_DECIMAL;
  int sign = 0;
  if (src < 0) {
    src *= -1;
    sign = 1;
  }
  set_sign(dst, sign);
  dst->bits[0] = src;
  *dst = normalize(*dst);
  return 0;
}