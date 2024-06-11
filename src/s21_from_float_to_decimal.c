#include <math.h>
#include <stdio.h>

#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  *dst = NULL_DECIMAL;
  int error = 0;
  error |= (0 < fabs(src) && fabs(src) < 1e-28);
  error |= (fabs(src) > 79228162514264333195497439231.0);
  error |= (isinf(src) || isnan(src));

  char str[15];
  for (int i = 0; i < 15; i++) {
    str[i] = '\0';
  }
  sprintf(str, "%.6e", src);
  int exp = 0;
  int pt1 = 0, pt2 = 0;
  sscanf(str, "%d.%de%d", &pt1, &pt2, &exp);

  if (pt1 < 0) pt1 *= -1;
  dst->bits[0] = pt1 * pow(10, 6) + pt2;
  exp -= 6;
  for (int i = 0; i < exp; i++) {
    mul_by_10(*dst, dst);
  }
  set_exponent(dst, 0);
  set_exponent(dst, -exp * (exp < 0));

  while (get_exponent(*dst) > 28) {
    *dst = div_by_10(*dst);
  }
  if (get_exponent(*dst) == 28) {
    float f = 0;
    s21_from_decimal_to_float(*dst, &f);
    if (src - f > 5 / pow(10, get_exponent(*dst) + 1)) {
      add_mantissas(*dst, ((s21_decimal){{1, 0, 0, 0}}), dst);
    }
  }
  *dst = normalize(*dst);
  set_sign(dst, src < 0);
  return error;
}