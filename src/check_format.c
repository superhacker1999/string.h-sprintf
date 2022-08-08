#include "s21_sprintf.h"
#include "s21_support_funcs.h"

void check_specificator(struct formating* new_format, const char** format,
                        int* flag) {
    for (int i = 0; i < SPECS_LEN; ++i) {
        if (**format == SPECS_LIST[i]) {
            switch (**format) {
                case 'c':
                    new_format->spec.c_enabled = 1;
                    *flag = IS_SPEC;
                    break;
                case 'd':
                    new_format->spec.d_enabled = 1;
                    *flag = IS_SPEC;
                    break;
                case 'i':
                    new_format->spec.i_enabled = 1;
                    *flag = IS_SPEC;
                    break;
                case 'f':
                    new_format->spec.f_enabled = 1;
                    *flag = IS_SPEC;
                    break;
                case 's':
                    new_format->spec.s_enabled = 1;
                    *flag = IS_SPEC;
                    break;
                case 'u':
                    new_format->spec.u_enabled = 1;
                    *flag = IS_SPEC;
                    break;
                case '%':
                    *flag = IS_PERCENT;
                    break;
                default:
                    break;
            }
        }
    }
}

void check_flag(struct formating* new_format, const char** format, int* flag) {
    for (s21_size_t i = 0; i < FLAGS_LEN; i++) {
        if (**format == FLAGS_LIST[i]) {
            switch (**format) {
                case '+':
                    new_format->flag.plus = 1;
                    *flag = IS_FLAG;
                    break;
                case '-':
                    new_format->flag.minus = 1;
                    *flag = IS_FLAG;
                    break;
                case ' ':
                    new_format->flag.space = 1;
                    *flag = IS_FLAG;
                    break;
                default:
                    break;
            }
        }
    }
}

void check_width(struct formating* new_format, const char** format, int* flag) {
    if (**format >= '0' && **format <= '9') {
        new_format->width = ascii_to_int(format);
        *flag = IS_WIDTH;
    }
}

void check_precision(struct formating* new_format, const char** format, int* flag) {
    if (**format == '.') {
        if (*(*format + 1) >= '0' && *(*format + 1) <= '9') {
            (*format)++;
            new_format->precision = ascii_to_int(format);
            *flag = IS_PRECISION;
        } else {
            new_format->precision = 0;
            *flag = IS_PRECISION;
            (*format)++;
        }
    }
}

int ascii_to_int(const char** str) {
    int res = 0;
    while (**str >= '0' && **str <= '9') {
        res = res * 10 + **str - '0';
        (*str)++;
    }
    return res;
}

void check_length(struct formating* new_format, const char** format, int* flag) {
    for (s21_size_t i = 0; i < LENGTHS_LEN; i++) {
        if (**format == LENGTH_LIST[i]) {
            switch (**format) {
                case 'h':
                    new_format->length.h_enabled = 1;
                    *flag = IS_LENGTH;
                    break;
                case 'l':
                    new_format->length.l_enabled = 1;
                    *flag = IS_LENGTH;
                    break;
            }
        }
    }
}
