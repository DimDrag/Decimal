#include <stdio.h>

#include "s21_decimal.h"

void s21_print_decimal(s21_decimal x) {
  for (int i = 3; i >= 0; i--) {
    printf("%d ", x.bits[i]);
  }
  printf("\n");
}

void s21_print_big_decimal(s21_big_decimal x) {
  for (int i = 7; i >= 0; i--) {
    printf("%d ", x.bits[i]);
  }
  printf("\n");
}