#include "s21_string.h"
#include "s21_support_funcs.h"

// Возвращает новую строку, в которой удаляются все начальные
// и конечные вхождения набора заданных символов (trim_chars) из данной строки (src)
s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2);

void *s21_trim(const char *src, const char *trim_char) {
    char *buffer = s21_NULL;

    if (src != s21_NULL) {
        s21_size_t length = s21_strlen(src);

        if (trim_char == s21_NULL) {
            trim_char = " ";
        }

        s21_size_t first_trim_num = s21_strspn(src, trim_char);
        s21_size_t last_trim_num = s21_trim_strspn_reverse(src, trim_char);

        if (length != first_trim_num) {
            buffer = x_calloc(length - first_trim_num - last_trim_num + 1, sizeof(char));
        } else {
            buffer = x_calloc(1, sizeof(char));
        }

        if (buffer != s21_NULL) {
            if (length != first_trim_num) {
                for (s21_size_t i = 0;
                     i < length - first_trim_num - last_trim_num; i++) {
                    buffer[i] = src[i + first_trim_num];
                }

                buffer[length - first_trim_num - last_trim_num] = '\0';
            } else {
                buffer[0] = '\0';
            }
        }
    }

    return buffer;
}

s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int is_continue = 0;
    int res = 0;

    for (int i = (int) str1len - 1; i > -1 && is_continue == 0; i--) {
        int inner_res = 0;

        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }

        if (inner_res == 0) {
            is_continue++;
            res--;
        }

        res++;
    }

    return res;
}

