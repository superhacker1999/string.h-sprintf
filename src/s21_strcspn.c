#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    while (*str1) {
        if (s21_strchr(str2, *str1)) {
            break;
        } else {
            str1++;
            len++;
        }
    }
    return len;
}
