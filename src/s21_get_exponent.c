#include "s21_decimal.h"

// get exponent of decimal number in base-10 form
unsigned int s21_get_decimal_exponent(s21_decimal x) {
  return (x.bits[3] << 1) >> 17;
}

// get exponent of big decimal number in base-10 form
unsigned int s21_get_big_decimal_exponent(s21_big_decimal x) {
  return (x.bits[7] << 1) >> 17;
}