#include "s21_decimal.h"

// returns integer part of decimal
int s21_truncate(s21_decimal value, s21_decimal *result) {
  value = normalize(value);
  while (get_exponent(value)) {
    value = div_by_10(value);
  }
  *result = value;
  *result = normalize(*result);
  return 0;
}