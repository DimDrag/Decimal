#include "s21_decimal.h"

// returns x < y
int s21_is_less(s21_decimal x, s21_decimal y) {
  return !is_greater_or_equal(x, y);
}