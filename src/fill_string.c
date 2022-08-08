#include "s21_sprintf.h"
#include "s21_support_funcs.h"

char* s_fillment(struct formating* new_format, char* arg) {
    char* temp_arg = arg;
    if (!temp_arg) temp_arg = "(null)";
    int arg_len = s21_strlen(temp_arg);  // находим длину строки arg
    int width = new_format->width;
    char tmp_arg[150];  // буфер для строки и ширины
    s21_memset(tmp_arg, 0, arg_len + width + 1);
    s21_memmove(tmp_arg, temp_arg, arg_len);  // копируем туда строку из аргумента
    find_precision_to_str(new_format, &arg_len, tmp_arg);
    // если есть точность сокращаем строку

    char* formatted_s = (char*)x_calloc((1000 + width + arg_len + 1), sizeof(char));
    // буфер длины ширина + arg
    s21_strcpy(formatted_s, tmp_arg);
    if (new_format->precision == 0 && width) {
        s21_memset(formatted_s, ' ', width);
    } else if (width) {
        add_width(new_format, formatted_s, arg_len);
    }
    formatted_s[width + arg_len] = '\0';
    return formatted_s;
}

void find_precision_to_str(struct formating* new_format, int* arg_len,
                           char* tmp_arg) {
    if (new_format->precision && new_format->precision < *arg_len) {
        *(tmp_arg + new_format->precision) = '\0';
        *arg_len = s21_strlen(tmp_arg);
    } else if (new_format->precision == 0) {
        tmp_arg[0] = '\0';
    }
}
