#include <math.h>

#include "s21_decimal.h"

// returns the remainder of division decimal by 10
int s21_get_decimal_rem_10(s21_decimal x) {
  int res = 0;
  for (int i = 2; i >= 0; i--) {
    res += x.bits[i] % 10 * pow(6, i);
  }
  return res % 10;
}

// returns the remainder of division big decimal by 10
int s21_get_big_decimal_rem_10(s21_big_decimal x) {
  int res = 0;
  for (int i = 6; i >= 0; i--) {
    res += x.bits[i] % 10 * pow(6, i);
  }
  return res % 10;
}