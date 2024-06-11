#include "s21_decimal.h"

// rounds decimal to closest integer using bank rounding
int s21_round(s21_decimal value, s21_decimal *result) {
  value = normalize(value);
  *result = NULL_DECIMAL;
  bool sign = get_sign(value);
  set_sign(&value, 0);

  s21_decimal trunc = NULL_DECIMAL;
  s21_truncate(value, &trunc);
  mul_by_10(trunc, &trunc);
  s21_decimal trunc_point_five = {{0, 0, 0, 1 << 16}};
  add_mantissas(trunc, ((s21_decimal){{5, 0, 0, 1 << 16}}), &trunc_point_five);
  s21_truncate(value, &trunc);

  if (get_exponent(value) == 0 || s21_is_less(value, trunc_point_five)) {
    *result = trunc;
  } else if (is_greater(value, trunc_point_five)) {
    add_mantissas(trunc, ((s21_decimal){{1, 0, 0, 0}}), result);
  } else {
    int rem10 = get_rem_10(trunc);  // остаток от деления на 10
    add_mantissas(trunc, ((s21_decimal){{rem10 % 2 != 0, 0, 0, 0}}), result);
  }
  set_sign(result, sign);
  *result = normalize(*result);
  return 0;
}