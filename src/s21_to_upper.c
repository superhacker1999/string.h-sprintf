#include "s21_string.h"
#include "s21_support_funcs.h"

void* s21_to_upper(const char* str) {
    s21_size_t i = 0;
    s21_size_t length = 0;
    char* buffer = s21_NULL;
    if (str) {
        length = s21_strlen(str);
        buffer = (char*)x_calloc(length + 1, sizeof(char));
    }
    if (str) {
        while (i <= length) {
            if (str[i] >= 97 && str[i] <= 122) {
                buffer[i] = str[i] - 32;
            } else {
                buffer[i] = str[i];
            }
            i++;
        }
    }
    return buffer;
}
