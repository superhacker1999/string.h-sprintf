#include "s21_string.h"

// Находит первое вхождение всей строки needle (не включая
// завершающий нулевой символ), которая появляется в строке haystack
char *s21_strstr(const char *haystack, const char *needle) {
    char *first_occurrence = s21_NULL;
    while (*haystack != '\0' && first_occurrence == s21_NULL) {
        char *tmp1 = (char *)haystack;
        char *tmp2 = (char *)needle;
        if (*tmp2 == '\0') {
            first_occurrence = (char*)tmp1;
        }

        while (*tmp1 == *tmp2 && first_occurrence == s21_NULL) {
            tmp1++;
            tmp2++;
            if (*tmp2 == '\0')
                first_occurrence = (char *)haystack;
        }
        haystack++;
    }
    return first_occurrence;
}
