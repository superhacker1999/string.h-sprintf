#include "s21_sprintf.h"
#include "s21_support_funcs.h"
#include <stdio.h>

char *f_fillment(va_list arg, struct formating *new_format) {
    double double_number;
    double float_number;
    char* str = x_calloc(1000 + new_format->width + 2, sizeof(char));
    if (new_format->length.l_enabled) {
        double_number = (double)va_arg(arg, double);
        float_caller(str, double_number, new_format);
    } else {
        double_number = va_arg(arg, double);
        float_number = double_number;
        float_caller(str, float_number, new_format);
    }
    find_flag_to_float(str, new_format);
    add_width_fl(str, new_format);
    return str;
}

char *float_caller(char *str, long double number,
                               struct formating *new_format) {
    if (new_format->precision < 0) new_format->precision = 6;
    float_to_ascii(str, number, new_format);
    return str;
}

char *float_to_ascii(char *str, long double number,
                             struct formating *new_format) {
  char num1_str[1000] = "", *p1 = s21_NULL;
  p1 = num1_str;
  char num2_str[1000] = "", *p2 = s21_NULL;
  p2 = num2_str;
  long double mantis, right = 0.0L, pow = 1.0L, pow_t = 1.0L;
  int sign;
  sign = signbit(number) == 0 ? 1 : -1;
  if (fpclassify(number) < 4) {
    edge_numbers(num1_str, number, new_format->precision);
    if (sign < 0 && fpclassify(number) != 1) s21_strcat(str, "-");
    s21_strcat(str, num1_str);
  } else {
    number = round_float(number, new_format->precision);
    mantis = modfl(fabsl(number), &right);
    while (truncl(right / pow) > 0) {
        int digit;
        digit = (int)truncl(fmodl(truncl(right), pow * (long double)10L) / (pow));
        *(p1++) = (char)(digit + '0');
        pow *= 10L;
    }
    if (sign < 0) *(p1++) = '-';
    *p1 = '\0';
    for (int i = 0; i < new_format->precision; i++) pow_t *= 10;
    mantis = roundl(mantis * pow_t);
    pow = 1.0L;
    while (pow < pow_t) {
        int digit;
        digit = (int)truncl(fmodl(truncl(mantis), pow * (long double)10L) / (pow));
        *(p2++) = (char)(digit + '0');
        pow *= 10L;
    }
    *p2 = '\0';
    reverse_str(num1_str);
    if (s21_strlen(num1_str) == 0) s21_strcat(str, "0");
    s21_strcat(str, num1_str);
    if (new_format->precision > 0) {
        s21_strcat(str, ".");
        reverse_str(num2_str);
        s21_strcat(str, num2_str);
    }
  }
  return str;
}

char *edge_numbers(char *str, long double x, int precission) {
  switch (fpclassify(x)) {
    case FP_NAN:
        s21_strcat(str, "nan");
        break;
    case FP_INFINITE:
        s21_strcat(str, "inf");
      break;
    case FP_ZERO:
        s21_strcat(str, "0");
        if (precission > 0) {
        s21_strcat(str, ".");
        while (precission--) s21_strcat(str, "0");
      }
      break;
  }
  return str;
}

char *reverse_str(char *str) {
  s21_size_t str_len = s21_strlen(str);
  char ch;
  for (s21_size_t i = 0; i < str_len / 2; i++) {
    ch = str[i];
    str[i] = str[str_len - 1 - i];
    str[str_len - 1 - i] = ch;
  }
  return str;
}

long double round_float(long double x, int precission) {
  long double right = 0.0;
  long double x1 = modfl(fabsl(x), &right);
  int mul = 0;
  int sign = signbit(x) == 0 ? 1 : -1;
  for (int i = 0; i < precission; i++) mul--;
  if (roundl(x1 / powl(10, mul)) > truncl(x1 / powl(10, mul))) {
    x = x + (5 * powl(10, mul - 1)) * sign;
  }
  if (precission <= 6 && x1 > 0) {
    x = x / powl(10, mul);
    x = truncl(x) * powl(10, mul);
  }
  return x;
}

char *find_flag_to_float(char *str, struct formating *new_format) {
  if ((*str >= '0' && *str <= '9') || *str == 'i') {
    char num_str[2] = "";
    char *p = s21_NULL;
    p = num_str;
    if (new_format->flag.plus)
      *(p++) = '+';
    else if (new_format->flag.space)
      *(p++) = ' ';
    *p = '\0';
    reverse_str(str);
    s21_strcat(str, num_str);
    reverse_str(str);
  }
  return str;
}

char *add_width_fl(char *str, struct formating *new_format) {
  int str_len = (int)s21_strlen(str);
  char *p = s21_NULL, *p2 = s21_NULL;
  p2 = str;
  if (new_format->width > (int)str_len) {
    char *num_str = calloc(1000 + new_format->width + 2, sizeof(char));
    if (num_str) {
      p = num_str;
      for (int i = 0; i < new_format->width; i++) {
        if (new_format->flag.minus == 1) {
          if (i < str_len) {
            *(p++) = *(p2++);
          } else {
              *(p++) = ' ';
          }
        } else {
          if (i < new_format->width - str_len) {
              *(p++) = ' ';
          } else {
            *(p++) = *(p2++);
          }
        }
      }
      num_str[new_format->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}
