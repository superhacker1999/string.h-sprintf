#include "s21_sprintf.h"
#include "s21_support_funcs.h"

int parse(struct formating *new_format, const char **format) {
    int exit_flag = 0;  // если флаг остается нулем, значит символ не является
                        // знаком формата
    for (int i = 0; i < 5 && exit_flag == 0; i++) {
        if (i == 0) {
            check_specificator((struct formating *)new_format, format, &exit_flag);
            // ищем спцификатор 1 или 6
        } else if (i == 1) {
            check_flag((struct formating *)new_format, format, &exit_flag);
            // ищем флаг 2
        } else if (i == 2) {
            check_width((struct formating *)new_format, format, &exit_flag);
            // ищем ширину 3
        } else if (i == 3) {
            check_precision((struct formating *)new_format, format, &exit_flag);
            // ищем точность 4
        } else if (i == 4) {
            check_length((struct formating *)new_format, format, &exit_flag);
            // ищем длину 5
        }
    }
    return exit_flag;
}

int parse_till_percent(struct formating *new_format, const char **format,
                       char **str, va_list arg, int *str_length) {
    int parse_result = 0;
    int is_null_sym = 0;
    while (**format != '%' && **format != '\0') {
        // пока не дойдем до следующего процента
        parse_result = parse(new_format, format);
        // проверяем входит ли символ в форматирование
        if (parse_result == NOT_VALID) {
            add_not_valid(format, str, str_length);
        } else if (parse_result == IS_SPEC) {
            // если символ спецификатор
            choose_specificator(new_format, str, arg, str_length);
            (*format)++;
            break;
        } else if (parse_result == IS_WIDTH || parse_result == IS_PRECISION) {
            // ширина (format двигается внутри функции)
            parse_result = 0;
        } else {  // флаг, длина
            (*format)++;
            parse_result = 0;
        }
    }
    if (parse_result != IS_SPEC && !is_null_sym) {
        check_percent(new_format, format, str, str_length);
    }
    return is_null_sym;
}

void check_percent(struct formating *new_format, const char **format,
                   char **str, int *str_length) {
    char *formatted = s21_NULL;
    if (**format != '\0') {
        formatted = c_fillment(new_format, '%');
        int len = s21_strlen(formatted);
        s21_memcpy(*str, formatted, len);
        *str_length += len;
        (*str) += len;
        free(formatted);
        (*format)++;
        add_not_valid(format, str, str_length);
    }
}

void add_not_valid(const char **format, char **str, int *str_length) {
    while (**format != '%' && **format != '\0') {
        **str = **format;
        (*str)++;
        (*format)++;
        *str_length += 1;
    }
}
