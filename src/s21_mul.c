#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  *result = NULL_DECIMAL;
  s21_big_decimal big_result = NULL_BIG_DECIMAL;
  // умножаем мантиссы
  for (int bit = 0; bit < 3; bit++) {
    for (int i = 31; i >= 0; i--) {
      if ((value_2.bits[bit] & (1 << i)) != 0) {
        s21_big_decimal tmp = s21_from_decimal_to_big_decimal(value_1);
        tmp = shift_left(tmp, 32 * bit + i);
        add_mantissas(big_result, tmp, &big_result);
      }
    }
  }
  // устанавливаем знак
  int sign = (get_sign(value_1) + get_sign(value_2)) % 2;
  set_sign(&big_result, sign);
  // складываем экспоненты
  int res_exp = get_exponent(value_1) + get_exponent(value_2);
  set_exponent(&big_result, res_exp);
  // // округляем результат
  *result = s21_round_big_decimal(big_result, &error);
  return error;
}