#include "s21_string.h"

//  Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str
char *s21_strchr(const char *str, int c) {
    do {
        if (*str == c) {
          return (char*)str;
        }
    } while (*str++);
    return (0);
}


