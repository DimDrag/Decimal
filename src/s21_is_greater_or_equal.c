#include "s21_decimal.h"

// returns x >= y
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y) {
  return is_equal(x, y) || is_greater(x, y);
}

// returns x >= y
int s21_big_is_greater_or_equal(s21_big_decimal x, s21_big_decimal y) {
  return is_equal(x, y) || is_greater(x, y);
}