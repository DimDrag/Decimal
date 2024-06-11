#include "s21_decimal.h"

// returns x <= y
int s21_is_less_or_equal(s21_decimal x, s21_decimal y) {
  return !is_greater(x, y);
}