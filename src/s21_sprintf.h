#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#include "s21_string.h"

enum Format {
    NOT_VALID,
    IS_SPEC,
    IS_FLAG,
    IS_WIDTH,
    IS_PRECISION,
    IS_LENGTH,
    IS_PERCENT
};

enum Lengths { FLAGS_LEN = 3, LENGTHS_LEN = 2, SPECS_LEN = 7 };

#define FLAGS_LIST "+- "
#define SPECS_LIST "cdifsu%"
#define LENGTH_LIST "hl"

struct flag {
    int plus;
    int minus;
    int space;
};

struct length {
    int h_enabled;
    int l_enabled;
};

struct spec {
    int c_enabled;
    int d_enabled;
    int i_enabled;
    int f_enabled;
    int s_enabled;
    int u_enabled;
};

struct formating {
    struct flag flag;
    int width;
    int precision;
    struct length length;
    struct spec spec;
};

#endif  // SRC_S21_SPRINTF_H_
