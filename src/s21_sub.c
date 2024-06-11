#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = NULL_DECIMAL;
  if (get_sign(value_1) != get_sign(value_2)) {
    set_sign(&value_2, get_sign(value_1));
    return s21_add(value_1, value_2, result);
  }  // сall s21_add, if signs of numbers differ
  int error_code = 0;
  value_1 = normalize(value_1);
  value_2 = normalize(value_2);
  int res_sign = get_sign(value_1);
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  if (is_greater(value_2, value_1)) {
    s21_swap_decimal(&value_1, &value_2);
    res_sign = (res_sign) ? 0 : 1;
  }
  s21_big_decimal big_value_1 = s21_from_decimal_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = s21_from_decimal_to_big_decimal(value_2);
  s21_big_decimal big_result = NULL_BIG_DECIMAL;
  set_exponent(&big_result, 28);
  set_sign(&big_result, get_sign(value_1));
  while (get_exponent(big_value_1) != 28) {
    mul_by_10(big_value_1, &big_value_1);
  }
  while (get_exponent(big_value_2) != 28) {
    mul_by_10(big_value_2, &big_value_2);
  }
  s21_sub_big_decimal_mantissas(big_value_1, big_value_2, &big_result);
  set_sign(&big_result, res_sign);
  *result = s21_round_big_decimal(big_result, &error_code);
  return error_code;
}