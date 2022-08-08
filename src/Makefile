TEST = all_tests

HEADER = s21_string.h s21_strerror.h s21_sprintf.h sprintf_support_funcs.h

OBJ = $(patsubst %.c, %.o, $(SRC) $(SPRINTF_SRC))
OBJ_TEST = $(patsubst %.c, %.o, $(SRC_TEST))
COVER_GCNO = $(patsubst %.o, %.gcno, $(OBJ) $(OBJ_TEST))
COVER_GCDA = $(patsubst %.o, %.gcda, $(OBJ) $(OBJ_TEST))
CC = gcc
SRC =	s21_memcmp.c s21_memset.c s21_strncpy.c s21_strcspn.c \
		s21_memchr.c s21_memmove.c s21_strchr.c s21_strncmp.c s21_strpbrk.c \
		s21_strtok.c s21_strstr.c s21_strrchr.c s21_strlen.c s21_strcpy.c \
		s21_strcmp.c s21_strncat.c s21_strcat.c s21_memcpy.c s21_strspn.c \
		s21_strerror.c s21_insert.c s21_to_lower.c s21_to_upper.c s21_trim.c

SPRINTF_SRC = s21_sprintf.c parsing.c check_format.c str_filling.c fill_char.c \
		fill_d_i.c fill_float.c fill_string.c fill_unsigned.c x_calloc.c
	
SRC_TEST = s21_string_test.c
CFLAGS := -Wall -Werror -Wextra -I. -g
LDFLAGS = -lcheck

.PHONY: all, clean, test, s21_string.a, gcov_report

all: clean s21_string.a test

s21_string.a: $(OBJ)
	ar rcs s21_string.a $?

%.o: %.c $(HEADER)
	$(CC) $(СFLAGS) -c $< -o $@ $(LDFLAGS)

test: $(TEST)

$(TEST):
	$(CC) $(CFLAGS) -g $(SRC) $(SPRINTF_SRC) $(SRC_TEST) -o $@ $(LDFLAGS) --coverage
	@echo "---------------------------TESTS--------------------------------------"
	./$(TEST)
	@echo "----------------------------------------------------------------------"

gcov_report: test 
	lcov -t "$(TEST)" -o $(TEST).info -c -d .	
	genhtml -o report $(TEST).info 

clean:
	@rm -rf $(OBJ) $(COVER_GCNO) $(OBJ_TEST) $(COVER_GCDA)  *.info *.gcda *.gcno
	@rm -rf $(TEST) report

