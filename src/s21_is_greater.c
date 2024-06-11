#include <stdlib.h>

#include "s21_decimal.h"

// returns x > y
int s21_is_greater(s21_decimal x, s21_decimal y) {
  s21_big_decimal big_x = s21_from_decimal_to_big_decimal(x);
  s21_big_decimal big_y = s21_from_decimal_to_big_decimal(y);
  return s21_big_is_greater(big_x, big_y);
}

// returns x > y
int s21_big_is_greater(s21_big_decimal x, s21_big_decimal y) {
  bool res = false;
  bool stop = false;
  int sign_x = get_sign(x);
  int sign_y = get_sign(y);
  if (sign_x != sign_y) {
    res = sign_y;
    stop = true;
  }
  s21_big_decimal* p_min_exp = (get_exponent(x) > get_exponent(y)) ? &y : &x;
  while (abs((int)get_exponent(x) - (int)get_exponent(y))) {
    mul_by_10(*p_min_exp, p_min_exp);
  }
  // определяем первый расходящийся бит
  for (int i = 6; !stop && i >= 0; i--) {
    if (x.bits[i] != y.bits[i]) {
      stop = true;
      res = (x.bits[i] > y.bits[i]) != sign_x;
    }
  }
  return res;
}
