#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim
char *s21_strtok(char *str, const char *delim) {
    static char *new = s21_NULL;
    if (!str) {
        str = new;
        if (str == s21_NULL) {
            return s21_NULL;
        }
    }
    str += s21_strspn(str, delim);
    if (*str == '\0') {
        new = s21_NULL;
        return new;
    }
    new = str + s21_strcspn(str, delim);
    if (new[0] != '\0') {
        new[0] = '\0';
        new++;
    } else {
        new = s21_NULL;
    }
    return str;
}

