#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки
void *s21_memchr(const void *str, int c, s21_size_t n) {
    s21_size_t i;
    int flag = 0;
    for (i = 0; i < n; i++) {
        if (*((char*)str + i) == c) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        str = s21_NULL;
    } else {
        str = (char*)str + i;
    }
    return (char*)str;
}
