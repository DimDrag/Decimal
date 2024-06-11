#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = NULL_DECIMAL;
  int error = 0;
  // деление на ноль
  if (is_equal(value_2, NULL_DECIMAL)) {
    return 3;
  }
  s21_big_decimal big_value_1 = s21_from_decimal_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = s21_from_decimal_to_big_decimal(value_2);
  s21_big_decimal big_result = NULL_BIG_DECIMAL;
  // домножаем мантиссу первого числа на 10, пока она не станет больше мантиссы
  // второго числа
  int exp = get_exponent(big_value_1);
  s21_big_decimal buff = NULL_BIG_DECIMAL;
  if (is_not_equal(value_1, NULL_DECIMAL)) {
    while (!mul_by_10(big_value_1, &buff)) {
      big_value_1 = buff;
      exp++;
    }
  }
  // делим столбиком
  big_value_1.bits[7] = 0;
  big_value_2.bits[7] = 0;
  for (int i = 223; i >= 32; i--) {
    if (is_greater_or_equal(shift_right(big_value_1, i), big_value_2)) {
      big_result = s21_big_decimal_or(
          big_result,
          shift_left(((s21_big_decimal){{1, 0, 0, 0, 0, 0, 0, 0}}), i));
      s21_sub_big_decimal_mantissas(big_value_1, shift_left(big_value_2, i),
                                    &big_value_1);
    }
  }
  // устанавливаем знак
  int sign = (get_sign(value_1) + get_sign(value_2)) % 2;
  set_sign(&big_result, sign);
  // складываем экспоненты
  set_exponent(&big_result, exp - get_exponent(value_2));
  // округляем результат
  *result = s21_round_big_decimal(big_result, &error);
  return error;
}