#include "s21_string.h"

// Копирует строку, на которую указывает src, в dest
char *s21_strcpy(char *dest, const char *src) {
    s21_size_t i = 0;
    for (; i < s21_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
