#include "s21_decimal.h"

bool s21_check_conversion(s21_big_decimal x) {
  int res = 0;
  for (int i = 3; i < 7; i++) {
    res += x.bits[i] != 0;
  }
  return res == 0;
}

s21_decimal s21_round_big_decimal(s21_big_decimal x, int* error) {
  s21_decimal result = NULL_DECIMAL;
  x = normalize(x);
  s21_big_decimal rem = x;
  int k = 0;
  // делим big decimal на 10 пока он не влелет в decimal или деление не станет
  // невозможным из-за экспоненты
  while (get_exponent(rem) > 28 ||
         (!s21_check_conversion(rem) && get_exponent(rem) != 0)) {
    rem = div_by_10(rem);
    k++;
  }
  result = s21_from_big_decimal_to_decimal(rem);
  // возвращаем ошибку (1 - число слишком велико, 2 - число слишком мало)
  if (!s21_check_conversion(rem)) {
    *error = 1 + get_sign(x);
  }
  // вычитаем то, что не влезло
  for (int i = 0; i < k; i++) {
    mul_by_10(rem, &rem);
  }
  s21_sub_big_decimal_mantissas(x, rem, &rem);
  // банковское округление
  s21_big_decimal five = {{5, 0, 0, 0, 0, 0, 0, 0}};
  set_sign(&rem, 0);
  for (int i = 0; i < k - 1; i++) {
    mul_by_10(five, &five);
  }
  set_exponent(&five, get_exponent(rem));
  if (is_greater(rem, five) ||
      (is_equal(rem, five) && get_rem_10(result) % 2)) {
    if (add_mantissas(result, ((s21_decimal){{1, 0, 0, 0}}), &result)) {
      *error = 1 + get_sign(x);
    }
  }
  result = normalize(result);
  return result;
}