#include <stdio.h>

#include "s21_decimal.h"

// print all bits of decimal number
void s21_print_decimal_bits(s21_decimal x) {
  for (int i = 31; i >= 0; i--) {
    if (i == 31) {
      printf("\033[01;34m%d\x1B[0;37;40m", (x.bits[3] & (1 << i)) != 0);
    } else if (16 <= i && i <= 23) {
      printf("\033[01;32m%d\x1B[0;37;40m", (x.bits[3] & (1 << i)) != 0);
    } else {
      printf("\033[01;30m%d\x1B[0;37;40m", (x.bits[3] & (1 << i)) != 0);
    }
  }
  for (int bit = 2; bit >= 0; bit--) {
    printf(" ");
    for (int i = 31; i >= 0; i--) {
      printf("%d", (x.bits[bit] & (1 << i)) != 0);
    }
  }
  printf("\n");
}

// print all bits of big decimal number
void s21_print_big_decimal_bits(s21_big_decimal x) {
  for (int i = 31; i >= 0; i--) {
    if (i == 31) {
      printf("\033[01;34m%d\x1B[0;37;40m", (x.bits[7] & (1 << i)) != 0);
    } else if (16 <= i && i <= 23) {
      printf("\033[01;32m%d\x1B[0;37;40m", (x.bits[7] & (1 << i)) != 0);
    } else {
      printf("\033[01;30m%d\x1B[0;37;40m", (x.bits[7] & (1 << i)) != 0);
    }
  }
  for (int bit = 6; bit >= 0; bit--) {
    printf(" ");
    for (int i = 31; i >= 0; i--) {
      printf("%d", (x.bits[bit] & (1 << i)) != 0);
    }
  }
  printf("\n");
}