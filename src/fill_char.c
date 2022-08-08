#include "s21_sprintf.h"
#include "s21_support_funcs.h"

char* c_fillment(struct formating* new_format, int arg) {
    int width = new_format->width;
    char *formatted_c = (char*)x_calloc(100 + width + 2, sizeof(char));  // буфер длины ширина + arg
    if (arg == '\0') {
        formatted_c[0] = '\0';
    } else {
        formatted_c[0] = arg;
        add_width(new_format, formatted_c, 1);
        formatted_c[width + 1] = '\0';
    }
    return formatted_c;
}

char* c_fillment_wchar(struct formating* new_format, char* arg, int *count_bytes) {
    int width = new_format->width;
    int len = s21_strlen(arg);
    int i = 0;
    char *formatted_c = (char*)x_calloc(100 + width + len + 1, sizeof(char));  // буфер длины ширина + arg
    for (; i < len; i++) {
        formatted_c[i] = arg[i];
        (*count_bytes)++;
    }
    add_width(new_format, formatted_c, len);
    formatted_c[width + i] = '\0';
    return formatted_c;
}
