#include "s21_decimal.h"

int s21_get_decimal_sign(s21_decimal x) { return x.bits[3] >> 31; }

int s21_get_big_decimal_sign(s21_big_decimal x) { return x.bits[7] >> 31; }