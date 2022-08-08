#include "s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
char *s21_strrchr(const char *str, int c) {  // на которую указывает аргумент str
    char *last_occurrence = s21_NULL;
    s21_size_t i = 0;
    for (; i < s21_strlen(str) + 1; i++) {
        if (str[i] == c) {
            last_occurrence = (char*)(str + i);
        }
    }
    return last_occurrence;
}
