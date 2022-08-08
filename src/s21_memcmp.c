#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int result = 0;
    s21_size_t i;
    const unsigned char* string1 = str1;
    const unsigned char* string2 = str2;
    for (i = 0; i < n; i++) {
        if (*(string1 + i) != *(string2 + i)) {
            result = 1;
            break;
        }
    }
    if (result == 1) {
        result = *(string1 + i) - *(string2 + i);
    }
    return result;
}

