#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest
char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest + s21_strlen(dest);
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
