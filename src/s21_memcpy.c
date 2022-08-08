#include "s21_string.h"

// Копирует n символов из src в dest
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *mem_dest = (char*)dest;
    const char *mem_src = (const char*)src;
    for (s21_size_t i = 0; i < n; i++) {
        mem_dest[i] = mem_src[i];
    }
    return mem_dest;
}
