#include <stdio.h>

#include "s21_decimal.h"
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = src.bits[2] * pow(2, 64) + src.bits[1] * pow(2, 32) + src.bits[0];
  *dst /= pow(10, get_exponent(src));
  if (get_sign(src)) *dst *= -1;
  return 0;
}