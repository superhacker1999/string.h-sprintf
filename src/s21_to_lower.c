#include "s21_string.h"
#include "s21_support_funcs.h"

void* s21_to_lower(const char* str) {
    s21_size_t i = 0;
    s21_size_t length = s21_strlen(str);
    char* buffer = s21_NULL;
    buffer =
        (char*)x_calloc(length + 1, sizeof(char));

    if (str) {
        while (i <= length) {
            if (str[i] >= 65 && str[i] <= 90) {
                buffer[i] = str[i] + 32;
            } else {
                buffer[i] = str[i];
            }
            i++;
        }
    }
    return buffer;
}
