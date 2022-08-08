#include "s21_sprintf.h"
#include "s21_support_funcs.h"

int s21_sprintf(char* str, const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    int parse_result = 0;
    struct formating new_format;
    int str_length = 0;

    while (*format != '\0') {
        s21_memset(&new_format, 0, sizeof(struct formating));
        new_format.precision = -1;
        if (*format == '%') {
            format++;
            parse_result = parse(&new_format, &format);
            if (parse_result == IS_PERCENT) {
                *str++ = '%';
                format++;
                str_length += 1;
                continue;
            } else if (parse_result == NOT_VALID) {
                add_not_valid(&format, &str, &str_length);
            } else if (parse_result == IS_SPEC) {
                choose_specificator(&new_format, &str, arg, &str_length);
                format++;
            } else {
                if (parse_till_percent(&new_format, &format, &str, arg, &str_length)) break;
            }
        } else {
            add_not_valid(&format, &str, &str_length);
        }
    }
    *str = '\0';
    return str_length;
}

