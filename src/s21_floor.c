#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  *result = NULL_DECIMAL;
  value = normalize(value);
  s21_decimal trunc = NULL_DECIMAL;
  s21_truncate(value, &trunc);
  *result = trunc;
  set_sign(result, get_sign(value));
  if (is_not_equal(value, trunc) && get_sign(value)) {
    add_mantissas(*result, ((s21_decimal){{1, 0, 0, 0}}), result);
  }
  return 0;
}