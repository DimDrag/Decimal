#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = 0;
  int error = 0;
  s21_truncate(src, &src);
  if (src.bits[2] != 0 || src.bits[1] != 0 || src.bits[0] > 2147483648) {
    error = 1;
  } else {
    *dst = src.bits[0];
    if (get_sign(src)) *dst *= -1;
  }
  if (*dst < 0 && get_sign(src) == 0) {
    error = 1;
  }
  return error;
}