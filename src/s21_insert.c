#include "s21_support_funcs.h"
#include "s21_string.h"
// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *buffer = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);
    s21_size_t memory_length = src_length + str_length + 1;
    if (start_index <= src_length) {
      buffer = x_calloc(memory_length, sizeof(char));
      if (buffer != s21_NULL) {
        for (s21_size_t i = 0; i < start_index; i++) {
          buffer[i] = src[i];
        }
        for (s21_size_t i = 0; i < str_length; i++) {
          buffer[i + start_index] = str[i];
        }
        for (s21_size_t i = 0; i < src_length - start_index; i++) {
          buffer[i + start_index + str_length] = src[i + start_index];
        }
        buffer[memory_length - 1] = '\0';
      }
    }
  }
  return buffer;
}
