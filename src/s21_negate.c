#include "s21_decimal.h"

// returns x * -1
int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  set_sign(result, 1 - get_sign(value));
  return 0;
}