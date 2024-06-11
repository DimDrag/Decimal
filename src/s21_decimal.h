#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <math.h>
#include <stdint.h>
#define true 1
#define false 0
typedef int bool;

#define NULL_DECIMAL \
  (s21_decimal) {    \
    { 0, 0, 0, 0 }   \
  }
#define NULL_BIG_DECIMAL       \
  (s21_big_decimal) {          \
    { 0, 0, 0, 0, 0, 0, 0, 0 } \
  }

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#define shift_right(X, SHIFT)                         \
  _Generic((X), s21_decimal                           \
           : s21_shift_decimal_right, s21_big_decimal \
           : s21_shift_big_decimal_right)(X, SHIFT)

#define shift_left(X, SHIFT)                         \
  _Generic((X), s21_decimal                          \
           : s21_shift_decimal_left, s21_big_decimal \
           : s21_shift_big_decimal_left)(X, SHIFT)

#define get_exponent(X)                                \
  _Generic((X), s21_decimal                            \
           : s21_get_decimal_exponent, s21_big_decimal \
           : s21_get_big_decimal_exponent)(X)

#define set_exponent(P_X, EXP)                           \
  _Generic((P_X), s21_decimal *                          \
           : s21_set_decimal_exponent, s21_big_decimal * \
           : s21_set_big_decimal_exponent)(P_X, EXP)

#define get_sign(X)                                \
  _Generic((X), s21_decimal                        \
           : s21_get_decimal_sign, s21_big_decimal \
           : s21_get_big_decimal_sign)(X)

#define set_sign(P_X, SIGN)                          \
  _Generic((P_X), s21_decimal *                      \
           : s21_set_decimal_sign, s21_big_decimal * \
           : s21_set_big_decimal_sign)(P_X, SIGN)

#define add_mantissas(X, Y, P_RESULT)                   \
  _Generic((X), s21_decimal                             \
           : s21_add_decimal_mantissas, s21_big_decimal \
           : s21_add_big_decimal_mantissas)(X, Y, P_RESULT)

#define div_by_10(X)                                \
  _Generic((X), s21_decimal                         \
           : s21_div_decimal_by_10, s21_big_decimal \
           : s21_div_big_decimal_by_10)(X)

#define mul_by_10(X, P_RESULT)                      \
  _Generic((X), s21_decimal                         \
           : s21_mul_decimal_by_10, s21_big_decimal \
           : s21_mul_big_decimal_by_10)(X, P_RESULT)

#define get_rem_10(X)                                \
  _Generic((X), s21_decimal                          \
           : s21_get_decimal_rem_10, s21_big_decimal \
           : s21_get_big_decimal_rem_10)(X)

#define normalize(X)                                \
  _Generic((X), s21_decimal                         \
           : s21_normalize_decimal, s21_big_decimal \
           : s21_normalize_big_decimal)(X)

#define print_bits(X)                                \
  _Generic((X), s21_decimal                          \
           : s21_print_decimal_bits, s21_big_decimal \
           : s21_print_big_decimal_bits)(X)

#define print(X)                                \
  _Generic((X), s21_decimal                     \
           : s21_print_decimal, s21_big_decimal \
           : s21_print_big_decimal)(X)

#define is_not_equal(X, Y)                     \
  _Generic((X), s21_decimal                    \
           : s21_is_not_equal, s21_big_decimal \
           : s21_big_is_not_equal)(X, Y)

#define is_equal(X, Y)                     \
  _Generic((X), s21_decimal                \
           : s21_is_equal, s21_big_decimal \
           : s21_big_is_equal)(X, Y)

#define is_greater(X, Y)                     \
  _Generic((X), s21_decimal                  \
           : s21_is_greater, s21_big_decimal \
           : s21_big_is_greater)(X, Y)

#define is_greater_or_equal(X, Y)                     \
  _Generic((X), s21_decimal                           \
           : s21_is_greater_or_equal, s21_big_decimal \
           : s21_big_is_greater_or_equal)(X, Y)

#define is_less_or_equal(X, Y)                     \
  _Generic((X), s21_decimal                        \
           : s21_is_less_or_equal, s21_big_decimal \
           : s21_big_is_less_or_equal)(X, Y)

// funcs for managing decimal
unsigned int s21_get_decimal_exponent(s21_decimal x);
void s21_set_decimal_exponent(s21_decimal* x, unsigned int exp);
s21_decimal s21_normalize_decimal(s21_decimal x);
int s21_mul_decimal_by_10(s21_decimal x, s21_decimal* result);
s21_decimal s21_div_decimal_by_10(s21_decimal x);
int s21_get_decimal_rem_10(s21_decimal x);
int s21_get_decimal_sign(s21_decimal x);
void s21_set_decimal_sign(s21_decimal* x, int sign);
int s21_add_decimal_mantissas(s21_decimal x, s21_decimal y,
                              s21_decimal* result);
void s21_swap_decimal(s21_decimal* x, s21_decimal* y);
s21_big_decimal s21_from_decimal_to_big_decimal(s21_decimal x);
s21_decimal s21_from_big_decimal_to_decimal(s21_big_decimal x);

// funcs for managing big decimal
unsigned int s21_get_big_decimal_exponent(s21_big_decimal x);
void s21_set_big_decimal_exponent(s21_big_decimal* x, unsigned int exp);
s21_big_decimal s21_normalize_big_decimal(s21_big_decimal x);
int s21_mul_big_decimal_by_10(s21_big_decimal x, s21_big_decimal* result);
s21_big_decimal s21_div_big_decimal_by_10(s21_big_decimal x);
int s21_get_big_decimal_rem_10(s21_big_decimal x);
int s21_get_big_decimal_sign(s21_big_decimal x);
void s21_set_big_decimal_sign(s21_big_decimal* x, int sign);
int s21_add_big_decimal_mantissas(s21_big_decimal x, s21_big_decimal y,
                                  s21_big_decimal* result);
void s21_sub_big_decimal_mantissas(s21_big_decimal x, s21_big_decimal y,
                                   s21_big_decimal* result);
s21_decimal s21_round_big_decimal(s21_big_decimal x, int* error);

int s21_big_is_equal(s21_big_decimal x, s21_big_decimal y);
int s21_big_is_not_equal(s21_big_decimal x, s21_big_decimal y);
int s21_big_is_greater(s21_big_decimal x, s21_big_decimal y);
int s21_big_is_greater_or_equal(s21_big_decimal x, s21_big_decimal y);

// bitwise operators for decimal
s21_decimal s21_shift_decimal_right(s21_decimal x, unsigned int shift);
s21_decimal s21_shift_decimal_left(s21_decimal x, unsigned int shift);
// bitwise operators for big decimal
s21_big_decimal s21_big_decimal_or(s21_big_decimal x, s21_big_decimal y);
s21_big_decimal s21_shift_big_decimal_right(s21_big_decimal x,
                                            unsigned int shift);
s21_big_decimal s21_shift_big_decimal_left(s21_big_decimal x,
                                           unsigned int shift);

// funcs mentioned in task

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_is_less(s21_decimal x, s21_decimal y);
int s21_is_less_or_equal(s21_decimal x, s21_decimal y);
int s21_is_greater(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y);
int s21_is_equal(s21_decimal x, s21_decimal y);
int s21_is_not_equal(s21_decimal x, s21_decimal y);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

// debugging funcs
void s21_print_decimal_bits(s21_decimal x);
void s21_print_big_decimal_bits(s21_big_decimal x);
void s21_print_decimal(s21_decimal x);
void s21_print_big_decimal(s21_big_decimal x);

#endif  // S21_DECIMAL_H