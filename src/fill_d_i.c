#include "s21_sprintf.h"
#include "s21_support_funcs.h"

char *d_fillment(struct formating* new_format, va_list arg) {
    long int temp_arg = 0;
    int precision = new_format->precision;
    length_cast(new_format, arg, &temp_arg);  // кастуем число если есть длина
    int length = count_char(temp_arg);
    if (precision && precision > length) {
        length = precision;  // если есть точность число становится длины точности
    }
    char *str_int = (char*)x_calloc((1000 + new_format->width + length + 2), sizeof(char));
    //  буфер для числа
    int_to_str(new_format, temp_arg, str_int);  // переводим число в строку
    add_width(new_format, str_int, s21_strlen(str_int));
    if (precision == 0 && temp_arg == 0) {  // если точность 0 и аргумент 0
        str_int[0] = '\0';
    }
    return str_int;
}

void length_cast(struct formating* new_format, va_list arg, long int* num) {
    // преобразование числа в соответствии с длиной
    if (new_format->length.h_enabled) {  // h
        short int a = va_arg(arg, int);
        *num = a;
    } else if (new_format->length.l_enabled) {  // l
        long int a = va_arg(arg, long int);
        *num = a;
    } else {
        int a = va_arg(arg, int);
        *num = a;
    }
}

void find_flag_to_int(struct formating* new_format, long int* number, char **str) {
    // обработка флагов + и пробел
    if (*number < 0) {
        **str = '-';
        *number *= -1;
        (*str)++;
    } else {
        if (new_format->flag.plus) {
            **str = '+';
            (*str)++;
        } else if (new_format->flag.space) {
            **str = ' ';
            (*str)++;
        }
    }
}

void find_precision_to_int(struct formating* new_format, char **str, long int number) {
    int zeroes_counter = 0;
    if (new_format->precision > 0) {
        while (zeroes_counter < new_format->precision - count_char(number)) {
            **str = '0';
            zeroes_counter++;
            (*str)++;
        }
    }
}

int count_char(long int number) {
    // считает количество цифр в числе
    int res = 0;
    if (number == 0)
        return 1;
    unsigned long long int num = number;
    while (num > 0) {
        res++;
        num /= 10;
    }
    return res;
}

char *int_to_str(struct formating* new_format, long int number, char *str) {
    // перевод числа в строку
    if (new_format->spec.d_enabled || new_format->spec.i_enabled) {
        find_flag_to_int(new_format, &number, &str);
        find_precision_to_int(new_format, &str, number);
    }
    unsigned long long int remainder = number;
    unsigned long long int power = 0;
    unsigned long long int counter = count_char(number);
    unsigned long long int num = number;
    while (counter > 0) {
        power = pow(10, counter - 1);
        *str++ = (remainder / power) + '0';
        remainder = num % power;
        counter--;
    }
    *str = '\0';
    return str;
}


