#include "s21_sprintf.h"
#include "s21_support_funcs.h"

char* u_fillment(struct formating* new_format, va_list arg) {
    unsigned long int temp_arg;
    u_length_cast(new_format, arg, &temp_arg);
    temp_arg = (long long int)temp_arg;

    int precision = new_format->precision;
    int length = count_unsigned_chars(temp_arg);
    if (precision && precision > length) length = precision;

    char* str_int = (char*)x_calloc((1000 + new_format->width + length + 1), sizeof(char));
    //  буфер для числа
    unsigned_to_str(new_format, temp_arg, str_int, length);  // переводим число в строку
    add_width(new_format, str_int, length);

    if (precision == 0 && temp_arg == 0) {  // если точность 0 и аргумент 0
        str_int[0] = '\0';
    }
    return str_int;
}

void u_length_cast(struct formating* new_format, va_list arg,
                   unsigned long int* num) {
    // преобразование числа в соответствии с длиной
    if (new_format->length.h_enabled) {  // h
        unsigned short int a = va_arg(arg, long int);
        *num = a;
    } else if (new_format->length.l_enabled) {  // l
        unsigned long int a = va_arg(arg, long int);
        *num = a;
    } else {
        unsigned int a = va_arg(arg, long int);
        *num = a;
    }
}

int count_unsigned_chars(unsigned long int number) {
    int res = 0;
    if (number == 0)
        return 1;
    while (number > 0) {
        res++;
        number /= 10;
    }
    return res;
}

char *unsigned_to_str(struct formating* new_format, unsigned long int number, char *str, int length) {
    // перевод числа в строку
    long int counter = length;
    find_precision_to_unsigned(new_format, &str, length);
    unsigned long int remainder = number;
    __uint128_t power = 0;
    while (counter > 0) {
        power = pow(10, counter - 1);
        *str++ = (remainder / power) + '0';
        remainder = number % power;
        counter--;
    }
    *str = '\0';
    return str;
}

void find_precision_to_unsigned(struct formating* new_format, char **str, int length) {
    int zeroes_counter = 0;
    if (new_format->precision) {
        while (zeroes_counter < new_format->precision - length) {
            **str = '0';
            zeroes_counter++;
            (*str)++;
        }
    }
}
