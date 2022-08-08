#include "s21_strerror.h"
#include "s21_string.h"
#include "s21_support_funcs.h"


int count_Char(int number) {
    int res = 0;
    if (number == 0)
        return 1;
    while (number > 0) {
        res++;
        number /= 10;
    }
    return res;
}

char *int_to_Str(int number, char *str) {
    int remainder = number;
    int counter = count_Char(number);
    int power = 0;
    while (counter > 0) {
        power = pow(10, counter - 1);
        *str++ = (remainder / power) + '0';
        remainder = number % power;
        counter--;
    }
    *str = '\0';
    return str;
}


char *s21_strerror(int errnum) {
    static char *error_list[] = ERRLIST;
    char *error_text = s21_NULL;
    static char unknown[42];

    if (errnum >= 0 && errnum < ERRLIST_LEN && s21_strcmp(error_list[errnum], "(null)") != 0) {
        error_text = (char *)error_list[errnum];
    } else {
        #if defined (__APPLE__)
        s21_strcpy(unknown, "Unknown error: ");
        #elif defined (__linux__)
        s21_strcpy(unknown, "Unknown error ");
        #endif
        char unknown_err_num[21];
        int_to_Str(errnum, unknown_err_num);
        s21_strcat(unknown, unknown_err_num);
        error_text = unknown;
    }
    return error_text;
}


