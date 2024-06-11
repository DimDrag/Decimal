#include "s21_decimal.h"

// multiplicates decimal by 10
// returns 1 if error
int s21_mul_decimal_by_10(s21_decimal x, s21_decimal* result) {
  // x*10 = x*8 + x*2 (x << 3 + x << 1)
  bool error = 0;
  s21_decimal shift3 = shift_left(x, 3);
  error = is_not_equal(x, shift_right(shift3, 3));
  s21_decimal shift1 = shift_left(x, 1);
  error |= add_mantissas(shift3, shift1, result);
  set_exponent(result, get_exponent(x) + 1);
  error |= (get_exponent(*result) > 28);
  return error;
}

// multiplicates big decimal by 10
// returns 1 if error
int s21_mul_big_decimal_by_10(s21_big_decimal x, s21_big_decimal* result) {
  // x*10 = x*8 + x*2 (x << 3 + x << 1)
  bool error = 0;
  s21_big_decimal shift3 = shift_left(x, 3);
  error = is_not_equal(x, shift_right(shift3, 3));
  s21_big_decimal shift1 = shift_left(x, 1);
  error |= add_mantissas(shift3, shift1, result);
  set_exponent(result, get_exponent(x) + 1);
  return error;
}