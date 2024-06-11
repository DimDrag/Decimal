#include "s21_decimal.h"

void s21_swap_decimal(s21_decimal* x, s21_decimal* y) {
  s21_decimal tmp = *x;
  *x = (*y);
  *y = tmp;
}