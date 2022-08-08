#include <string.h>
#include <stdio.h>
#include <check.h>
#include <errno.h>
#include <stdlib.h>
#include "s21_string.h"

// STRLEN

START_TEST(STRLENTest1) {
    char str[] = "Hello";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST

START_TEST(STRLENTest2) {
    char str[] = "Hegd    llo";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 11");
}
END_TEST

START_TEST(STRLENTest3) {
    char str[] = "";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 0");
}
END_TEST

START_TEST(STRLENTest4) {
    char str[] = "lorem\\tipsum\\tdolor\\sit\\amet\\ ";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 32");
}
END_TEST
START_TEST(STRLENTest5) {
    char str[] = "  \f\r\t";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST
START_TEST(STRLENTest6) {
    char str[] = "     ";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST

// STRCHR

START_TEST(STRCHRTest1) {
    char str[] = "Hello world";
    int ch = 'w';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest2) {
    char str[] = "Hello world";
    int ch = 'o';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest3) {
    char str[] = "Hello world";
    int ch = 'c';
    ck_assert_ptr_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest4) {
    char str[] = "Hello world";
    int ch = 'H';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest5) {
    char str[] = "Hello world";
    int ch = '\0';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest6) {
    char str[] = "";
    int ch = '\0';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

// STRSPN

START_TEST(STRSPNTest1) {
    char *str1 = "12345";
    char *str2 = "123";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 3");
}
END_TEST

START_TEST(STRSPNTest2) {
    char *str1 = "12345";
    char *str2 = "12sd34";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 4");
}
END_TEST


START_TEST(STRSPNTest3) {
    char *str1 = "12345";
    char *str2 = "12sdf4";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 2");
}
END_TEST

START_TEST(STRSPNTest4) {
    char *str1 = "12345";
    char *str2 = "kbf";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 0");
}
END_TEST

START_TEST(STRSPNTest5) {
    char *str1 = "12345";
    char *str2 = "54321";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2) , "Failed on 5");
}
END_TEST

START_TEST(STRSPNTest6) {
    char *str1 = "12345";
    char *str2 = "5qw4w3qwe2qweqw1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 5");
}
END_TEST

START_TEST(STRSPNTest7) {
    char *str1 = "12345";
    char *str2 = " ";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 0");
}
END_TEST

START_TEST(STRSPNTest8) {
    char *str1 = "12345";
    char *str2 = " 1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 1");
}
END_TEST


// STRCSPN

START_TEST(STRCSPNTest1) {
    char *src = "0123456789";
    char *str = "54";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 4");
}
END_TEST

START_TEST(STRCSPNTest2) {
    char *src = "0123456789";
    char *str = "e";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST


START_TEST(STRCSPNTest3) {
    char *src = "46";
    char *str = "123";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 2");
}
END_TEST

START_TEST(STRCSPNTest4) {
    char *src = "HELLO";
    char *str = "HELLO";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

START_TEST(STRCSPNTest5) {
    char *src = "";
    char *str = "hi";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST
START_TEST(STRCSPNTest6) {
    char *src = "\0";
    char *str = "\0";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

// MEMCPY

START_TEST(MEMCPYTest1) {
    char *src = "HELLO WORLD";
    char dest[15];
    char dest2[15];
    ck_assert_mem_eq(s21_memcpy(dest, src, 11), memcpy(dest2, src, 11), 11);
}
END_TEST

START_TEST(MEMCPYTest2) {
    char *src = "HELLO";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest3) {
    char *src = "HELLO";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

START_TEST(MEMCPYTest4) {
    char *src = "zy\0xw";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

START_TEST(MEMCPYTest5) {
    char *src = "zy\0xw";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

// STRCAT
START_TEST(STRCATTest1) {
    char app[1024]="вторая строка ";
    char dst[1024]="первая строка ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest2) {
    char app[1024]=" ";
    char dst[1024]="   ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest3) {
    char app[1024]="s s d";
    char dst[1024]=" s  s  s  sd aff   ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST


START_TEST(STRCATTest4) {
    char app[1024]="sdddadasdsa";
    char dst[1024]="s                              ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest5) {
    char app[1024]="\0";
    char dst[1024]=" \0";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

// MEMCMP
START_TEST(MEMCMPTest1) {
    char str1[] = "Hello";
    char str2[] = "Hello";
    int n = 6;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest2) {
    char str1[] = "Hello";
    char str2[] = "Help";
    int n = 4;
    ck_assert_int_lt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest3) {
    char str1[] = "Help";
    char str2[] = "Hello";
    int n = 4;
    ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest4) {
    char str1[] = "Help";
    char str2[] = "Hello";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest5) {
    char str1[] = "Hello";
    char str2[] = "";
    int n = 4;
    ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest6) {
    char str1[] = "";
    char str2[] = "";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest7) {
    char str1[] = "gsafh";
    char str2[] = "dhkjfhs";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest8) {
    char str1[] = "test\0test";
    char str2[] = "test";
    int n = 10;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest9) {
    char str1[] = "test";
    char str2[] = "teSt";
    int n = 4;
    ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest10) {
    char str1[] = "t\200";
    char str2[] = "t\0";
    int n = 2;
    ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

// STRNCAT
START_TEST(STRNCATTest1) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 6;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest2) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 4;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest3) {
    char str1[1024] = "";
    char str2[] = " HELLO";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest4) {
    char str1[1024] = "HI, ";
    char str2[] = "HELL\0O";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest5) {
    char str1[1024] = "\0";
    char str2[] = "H";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

// STRNCPY

START_TEST(STRNCPYTest1) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 6;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest2) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 4;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest3) {
    char str1[1024] = "";
    char str2[] = " HELLO";
    int n = 5;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest4) {
    char str1[1024] = "HI, ";
    char str2[] = " HELL\0O";
    int n = 5;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest5) {
    char str1[1024] = "HI, ";
    char str2[] = " HELLO";
    int n = 20;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

// STRRCHR
START_TEST(STRRCHRTest1) {
    char str1[] = "Hello, Mel";
    int c = 'e';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest2) {
    char str1[] = "Hello, Mel";
    int c = 'p';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest3) {
    char str1[] = "";
    int c = 'l';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest4) {
    char str1[] = "Hello";
    int c = 0;
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest5) {
    char str1[] = "Hello";
    int c = 'o';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

// MEMMOVE

START_TEST(MEMMOVETest1) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[20] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1+2, src+2, 3), memmove(dest2, src+2, 3), 5);
}
END_TEST

START_TEST(MEMMOVETest2) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[20] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1, src, 0), memmove(dest2, src, 0), 0);
}
END_TEST

START_TEST(MEMMOVETest3) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[20] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1, src, 9), memmove(dest2, src, 9), 0);
}
END_TEST

START_TEST(MEMMOVETest4) {
    char dest1[10] = "";
    char dest2[10] = "";
    char src[20] = "so\0";
    ck_assert_mem_eq(s21_memmove(dest1, src, 10), memmove(dest2, src, 10), 0);
}
END_TEST

START_TEST(MEMMOVETest5) {
    char str[] = "iloveworld";
    char str_test[] = "iloveworld";
    s21_memmove(str, str + 5, 5);
    memmove(str_test, str_test + 5, 5);
    ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest6) {
    char str[] = "iloveworld";
    char str_test[] = "iloveworld";
    s21_memmove(str + 5, str, 5);
    memmove(str_test + 5, str_test, 5);
    ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest7) {
    char str[] = "iloveworld";
    char str_test[] = "iloveworld";
    s21_memmove(str, str + 4, 7);
    memmove(str_test, str_test + 4, 7);
    ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest8) {
    char str[] = "iloveworld";
    char str_test[] = "iloveworld";
    s21_memmove(str + 3, str, 5);
    memmove(str_test + 3, str_test, 5);
    ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest9) {
    char str[] = "iloveworld";
    char str_test[] = "iloveworld";
    s21_memmove(str + 4, str + 3, 3);
    memmove(str_test + 4, str_test + 3, 3);
    ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest10) {
    char str[] = "iloveworld";
    char str_test[] = "iloveworld";
    s21_memmove(str, str, 3);
    memmove(str_test, str_test, 3);
    ck_assert_str_eq(str, str_test);
}
END_TEST

// STRSTR

START_TEST(STRSTRTest1) {
    char str1[10] = "hello";
    char str2[10] = "he";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest2) {
    char str1[10] = "hello";
    char str2[10] = "";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest3) {
    char str1[10] = "hello";
    char str2[10] = "qw";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest4) {
    char str1[10] = "hello";
    char str2[10] = "hellp";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest5) {
    char str1[1024] = "hello sweet hello";
    char str2[10] = "hello";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST


// STRCMP

START_TEST(STRCMPTest1) {
    char str1[10] = "hello";
    char str2[10] = "hello";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(STRCMPTest2) {
    char str1[10] = "hello";
    char str2[10] = "hellq";
    ck_assert_int_lt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest3) {
    char str1[10] = "hello";
    char str2[10] = "helle";
    ck_assert_int_gt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest4) {
    char str1[10] = "hello";
    char str2[10] = "";
    ck_assert_int_gt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest5) {
    char str1[10] = "";
    char str2[10] = "hello";
    ck_assert_int_lt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest6) {
    char str1[10] = "";
    char str2[10] = "";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST


// MEMCHR

START_TEST(MEMCHRTest1) {
    char str1[10] = "Hello";
    ck_assert_mem_eq(s21_memchr(str1, 'H', 5), memchr(str1, 'H', 5), 5);
}
END_TEST


START_TEST(MEMCHRTest2) {
    char str1[10] = "Hello";
    ck_assert_msg(s21_memchr(str1, 'h', 5) == s21_NULL, "Failed: Str == s21_NULL");
}
END_TEST


START_TEST(MEMCHRTest3) {
    char str1[10] = "Hellosdsfq";
    ck_assert_msg(s21_memchr(str1, 'h', 5) == s21_NULL, "Failed: Str == s21_NULL");
}
END_TEST

START_TEST(MEMCHRTest4) {
    char str1[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1, 'l', 5), memchr(str1, 'l', 5), 3);
}
END_TEST

START_TEST(MEMCHRTest5) {
    char str1[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1, 'l', 0), memchr(str1, 'l', 0), 0);
}
END_TEST


// STRCPY

START_TEST(STRCPYTest1) {
    char str[] = "Hello";
    char str1[15];
    char str2[15];
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(STRCPYTest2) {
    char str[] = "";
    char str1[15];
    char str2[15];
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest3) {
    char str[] = "";
    char str1[15] = "test";
    char str2[15] = "test";
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest4) {
    char str[] = "Test";
    char str1[1024];
    char str2[1024];
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

// STRPBRK

START_TEST(STRPBRKTest1) {
    char *str = "this is a test";
    char *str1 = "this is a test";
    str1 = strpbrk(str1, "this");
    str = s21_strpbrk(str, "this");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest2) {
    char *str = "this is a test";
    char *str1 = "this is a test";
    str1 = strpbrk(str1, " ");
    str = s21_strpbrk(str, " ");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest3) {
    char *str = "this is a test, this is ...";
    char *str1 = "this is a test, this is ...";
    str1 = strpbrk(str1, "this");
    str = s21_strpbrk(str, "this");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest4) {
    char *str = "this is a test, this is ...";
    char *str1 = "this is a test, this is ...";
    ck_assert_ptr_eq(s21_strpbrk(str, "prom"), strpbrk(str1, "prom"));
}
END_TEST

// STRNCMP

START_TEST(STRNCMPTest1) {
    char *str1 = "1234567890";
    char *str2 = "1234567890";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest2) {
    char *str1 = "1234567890";
    char *str2 = "1224567890";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest3) {
    char *str1 = "1224567890";
    char *str2 = "1234567890";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest4) {
    char *str1 = "";
    char *str2 = "";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest5) {
    char *str1 = "1224567890";
    char *str2 = "";
    ck_assert_int_gt(s21_strncmp(str1, str2, 5), 0);
}
END_TEST

START_TEST(STRNCMPTest6) {
    char *str1 = "122";
    char *str2 = "345";
    ck_assert_int_lt(s21_strncmp(str1, str2, 5), 0);
}
END_TEST

START_TEST(STRNCMPTest7) {
    char *str1 = "test\0abc";
    char *str2 = "test\0";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest8) {
    char *str1 = "1224567890";
    char *str2 = "02";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

// MEMSET

START_TEST(MEMSETTest1) {
    char str1[15] = "1234567890";
    char str2[15] = "1234567890";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest2) {
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest3) {
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = 'q';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest4) {
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = '1';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 5);
}
END_TEST

START_TEST(MEMSETTest5) {
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "ewqewqewqewq";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest6) {
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "qweqweqweqwe";
    int c = '\0';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest7) {
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "qweqweqweqwe";
    int c = ' ';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

// STRTOK

START_TEST(STRTOKTest2) {
    char str[30] = "test1/test2/test3/test4";
    char *delim = ",";
    ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 2");
}
END_TEST

START_TEST(STRTOKTest3) {
    char str[30] = "test1/test2/test3/test4";
    char* delim = "e";
    ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 3");
}
END_TEST

START_TEST(STRTOKTest4) {
    char str[30] = "AadacAdxa";
    char* delim = "a";
    ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 4");
}
END_TEST

START_TEST(STRTOKTest5) {
    char str[30] = "ased dse c sze wsew";
    char* delim = "e";
    ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 5");
}
END_TEST

START_TEST(STRTOKTest6) {
    char dest8[] = "test1/test2/test3/test4";
    char orig8[] = "test1/test2/test3/test4";
    ck_assert_str_eq(s21_strtok(dest8, "/"), strtok(orig8, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

    char dest9[] = "test1/test2/test3///";
    char orig9[] = "test1/test2/test3///";
    ck_assert_str_eq(s21_strtok(dest9, "/"), strtok(orig9, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

    char dest10[] = "///test1///test2/test3/";
    char orig10[] = "///test1///test2/test3/";
    ck_assert_str_eq(s21_strtok(dest10, "/"), strtok(orig10, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
}
END_TEST

// STRERROR

START_TEST(STRERRORTest2) {
    for (int i = 0; i < 107; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(STRERRORTest3) {
    for (int i = 134; i < 234; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

// TO_UPPER
START_TEST(TOUPPERTest1) {
    char str[4] = "abc";
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_str_eq(str1, "ABC");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest2) {
    char str[12] = "Hello World";
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_str_eq(str1, "HELLO WORLD");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest3) {
    char str[1] = "";
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_str_eq(str1, "");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest4) {
    char str[4] = "ABC";
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_str_eq(str1, "ABC");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest5) {
    char str[6] = "1234a";
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_str_eq(str1, "1234A");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest6) {
    char* str = s21_NULL;
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_ptr_eq(str1, s21_NULL);
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest7) {
    char str[12] = "abc\0hello";
    char *str1 = (char *)s21_to_upper(str);
    ck_assert_str_eq(str1, "ABC");
    free(str1);
}
END_TEST

// INSERT
START_TEST(INSERTTest1) {
    char str1[10] = "abc";
    char str2[10] = "1234";
    char *str3 = (char *)s21_insert(str1, str2, 2);
    ck_assert_str_eq(str3, "ab1234c");
    free(str3);
}
END_TEST

START_TEST(INSERTTest2) {
    char str1[10] = "1";
    char str2[10] = "1234";
    char *str3 = (char *)s21_insert(str2, str1, 1);
    ck_assert_str_eq(str3, "11234");
    free(str3);
}
END_TEST

START_TEST(INSERTTest3) {
    char str1[10] = "1234";
    char str2[10] = " ";
    char *str3 = (char *)s21_insert(str1, str2, 1);
    ck_assert_str_eq(str3, "1 234");
    free(str3);
}
END_TEST

START_TEST(INSERTTest4) {
    char str1[4] = "abc";
    char str2[2] = " ";
    char *str3 = (char *)s21_insert(str1, str2, 2);
    ck_assert_str_eq(str3, "ab c");
    free(str3);
}
END_TEST

START_TEST(INSERTTest6) {
    char str1[4] = "abc";
    char str2[5] = "1234";
    char *str3 = (char *)s21_insert(str1, str2, 0);
    ck_assert_str_eq(str3, "1234abc");
    free(str3);
}
END_TEST

START_TEST(INSERTTest7) {
    char* str1 = s21_NULL;
    char str2[5] = "1234";
    char *str3 = (char *)s21_insert(str1, str2, 0);
    ck_assert_ptr_eq(str3, s21_NULL);
    free(str3);
}
END_TEST


// TO_LOWER
START_TEST(TOLOWERTest1) {
    char str[4] = "abc";
    char *str2 = (char *)s21_to_lower(str);
    ck_assert_str_eq(str2, "abc");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest2) {
    char str[12] = "Hello World";
    char *str2 = (char *)s21_to_lower(str);
    ck_assert_str_eq(str2, "hello world");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest3) {
    char str[1] = "";
    char *str2 = (char *)s21_to_lower(str);
    ck_assert_str_eq(str2, "");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest4) {
    char str[4] = "ABC";
    char *str2 = (char *)s21_to_lower(str);
    ck_assert_str_eq(str2, "abc");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest5) {
    char str[6] = "1234a";
    char *str2 = (char *)s21_to_lower(str);
    ck_assert_str_eq(str2, "1234a");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest6) {
    // char *str = s21_NULL;
    // char *str2 = (char *)s21_to_lower(str);
    // ck_assert_ptr_eq(str2, s21_NULL);
    // free(str2);
}
END_TEST

START_TEST(TOLOWERTest7) {
    char *str = "WoW\0, I love it!";
    char *str2 = (char *)s21_to_lower(str);
    ck_assert_str_eq(str2, "wow");
    free(str2);
}
END_TEST

// TRIM


START_TEST(TRIMTest13) {
    char *res = s21_trim("testc", "c");
    ck_assert_str_eq(res, "test");
    free(res);

    res = s21_trim(" test ", " ");
    ck_assert_str_eq(res, "test");
    free(res);

    res = s21_trim(" ", " ");
    ck_assert_str_eq(res, "");
    free(res);

    res = s21_trim("*te*st*", "*");
    ck_assert_str_eq(res, "te*st");
    free(res);

    res = s21_trim(" te st001", " ");
    ck_assert_str_eq(res, "te st001");
    free(res);

    res = s21_trim(" /*()", ")(/ *");
    ck_assert_str_eq(res, "");
    free(res);
}
END_TEST


// SPRINTF

START_TEST(s21_sprintf_test_2) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    sprintf(data, "|%32s| ", "111");
    s21_sprintf(data1, "|%32s| ", "111");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_3) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    sprintf(data, "|%32s| ", "abc");
    s21_sprintf(data1, "|%32s| ", "abc");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_4) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    sprintf(data, "|%-32s| ", "abc");
    s21_sprintf(data1, "|%-32s| ", "abc");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_5) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    sprintf(data, "|%16s| ", "nark nark");
    s21_sprintf(data1, "|%16s| ", "nark nark");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_6) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    sprintf(data, "|%16s| ", "nark nark");
    s21_sprintf(data1, "|%16s| ", "nark nark");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_8) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int c = s21_sprintf(data, "|%.3s| kushat nado |%20s| ", "MneEEEEEEEEE", "arbuz");
    int d = sprintf(data1, "|%.3s| kushat nado |%20s| ", "MneEEEEEEEEE", "arbuz");
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_10) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int c = s21_sprintf(data, "|%-20.18u| ", -345);
    int d = sprintf(data1, "|%-20.18u| ", -345);
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_11) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int c = s21_sprintf(data, "|%-20.18d| ", -345);
    int d = sprintf(data1, "|%-20.18d| ", -345);
    ck_assert_int_eq(c, d);
}


START_TEST(s21_sprintf_test_12) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int c = s21_sprintf(data, "|%%| ");
    int d = sprintf(data1, "|%%| ");
    ck_assert_int_eq(c, d);
}
END_TEST


START_TEST(s21_sprintf_test_13) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int c = s21_sprintf(data, "|test %-12i et %24s !| ", 0, "coco");
    int d = sprintf(data1, "|test %-12i et %24s !| ", 0, "coco");
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(s21_sprintf_test_15) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%c| ", 'a');
    sprintf(data1, "01)SPRINTF : |%c| ", 'a');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_16) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-c| ", 'z');
    sprintf(data1, "01)SPRINTF : |%-c| ", 'z');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_18) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%5c| ", 'R');
    sprintf(data1, "01)SPRINTF : |%5c| ", 'R');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_19) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-5c| ", 'R');
    sprintf(data1, "01)SPRINTF : |%-5c| ", 'R');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_20) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%1c| ", '3');
    sprintf(data1, "01)SPRINTF : |%1c| ", '3');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_21) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int a = s21_sprintf(data, "01)SPRINTF : |%10c%s", '\0', "lol");
    int b = sprintf(data1, "01)SPRINTF : |%10c%s", '\0', "lol");
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_22) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int a = s21_sprintf(data, "01)SPRINTF : |%5c|", '\0');
    int b = sprintf(data1, "01)SPRINTF : |%5c|", '\0');
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_23) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int a = s21_sprintf(data, "01)SPRINTF : |%-5c|", '\0');
    int b = sprintf(data1, "01)SPRINTF : |%-5c|", '\0');
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_24) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    int a = s21_sprintf(data, "01)SPRINTF : |%s|", "\0");
    int b = sprintf(data1, "01)SPRINTF : |%s|", "\0");
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sprintf_test_25) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%s| ", "salut");
    sprintf(data1, "01)SPRINTF : |%s| ", "salut");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_26) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-s| ", "test");
    sprintf(data1, "01)SPRINTF : |%-s| ", "test");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_28) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%10s| ", "42");
    sprintf(data1, "01)SPRINTF : |%10s| ", "42");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_29) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-10s| ", "42");
    sprintf(data1, "01)SPRINTF : |%-10s| ", "42");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_30) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%2s| ", "string");
    sprintf(data1, "01)SPRINTF : |%2s| ", "string");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_31) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-2s| ", "string");
    sprintf(data1, "01)SPRINTF : |%-2s| ", "string");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_32) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%.15s| ", "precision");
    sprintf(data1, "01)SPRINTF : |%.15s| ", "precision");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_33) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%.4s| ", "precision");
    sprintf(data1, "01)SPRINTF : |%.4s| ", "precision");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_34) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%.0s| ", "precision");
    sprintf(data1, "01)SPRINTF : |%.0s| ", "precision");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_35) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%s| ", "\0\0\0\0\0");
    sprintf(data1, "01)SPRINTF : |%s| ", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_36) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%10s| ", "\0\0\0\0\0");
    sprintf(data1, "01)SPRINTF : |%10s| ", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_37) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%s| ", "");
    sprintf(data1, "01)SPRINTF : |%s| ", "");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_38) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-.2s| ", "boom");
    sprintf(data1, "01)SPRINTF : |%-.2s| ", "boom");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_39) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%10.8s| ", "google");
    sprintf(data1, "01)SPRINTF : |%10.8s| ", "google");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_40) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%10.2s| ", "twitter");
    sprintf(data1, "01)SPRINTF : |%10.2s| ", "twitter");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_41) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%2.10s| ", "samsung");
    sprintf(data1, "01)SPRINTF : |%2.10s| ", "samsung");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_42) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%10s| ", "sprintf");
    sprintf(data1, "01)SPRINTF : |%10s| ", "sprintf");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_43) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-10.2s| ", "424242424242");
    sprintf(data1, "01)SPRINTF : |%-10.2s| ", "424242424242");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_44) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%1.0s| ", "123456789");
    sprintf(data1, "01)SPRINTF : |%1.0s| ", "123456789");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_45) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-1.0s| ", "123456789");
    sprintf(data1, "01)SPRINTF : |%-1.0s| ", "123456789");
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_46) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%.1s| ", "covid-19");
    sprintf(data1, "01)SPRINTF : |%.1s| ", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_47) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%10.2s| ", "covid-19");
    sprintf(data1, "01)SPRINTF : |%10.2s| ", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_48) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%2.5s| ", "covid-19");
    sprintf(data1, "01)SPRINTF : |%2.5s| ", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_49) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%-10.2s| ", "covid-19");
    sprintf(data1, "01)SPRINTF : |%-10.2s| ", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_50) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "01)SPRINTF : |%1.4s| et |%-6.8s| et |%4.2s| ", "tuuu", "12345", "hu");
    sprintf(data1, "01)SPRINTF : |%1.4s| et |%-6.8s| et |%4.2s| ", "tuuu", "12345", "hu");
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_51) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%1.1d| ", -20);
    sprintf(data1, "02) standart PRINTF :|%1.1d| ", -20);
}
END_TEST

START_TEST(s21_sprintf_test_52) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%-10d| ", -50);
    sprintf(data1, "02) standart PRINTF :|%-10d| ", -50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_53) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%2d| ", -20);
    sprintf(data1, "02) standart PRINTF :|%2d| ", -20);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_54) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%.2d| ", -20);
    sprintf(data1, "02) standart PRINTF :|%.2d| ", -20);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_55) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%d| ", 42);
    sprintf(data1, "02) standart PRINTF :|%d| ", 42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_56) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%i| ", 42);
    sprintf(data1, "02) standart PRINTF :|%i| ", 42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_57) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%-d| ", 42);
    sprintf(data1, "02) standart PRINTF :|%-d| ", 42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_58) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%10d| ", 100);
    sprintf(data1, "02) standart PRINTF :|%10d| ", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_59) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%-10d| ", 100);
    sprintf(data1, "02) standart PRINTF :|%-10d| ", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_60) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%.10d| ", 100);
    sprintf(data1, "02) standart PRINTF :|%.10d| ", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_61) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%10.5d| ", 100);
    sprintf(data1, "02) standart PRINTF :|%10.5d| ", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_62) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%5.10d| ", 64);
    sprintf(data1, "02) standart PRINTF :|%5.10d| ", 64);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_63) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%1.1d| ", 16);
    sprintf(data1, "02) standart PRINTF :|%1.1d| ", 16);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_64) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%d| ", -42);
    sprintf(data1, "02) standart PRINTF :|%d| ", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_65) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%10d| ", -42);
    sprintf(data1, "02) standart PRINTF :|%10d| ", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_66) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%.10d| ", -42);
    sprintf(data1, "02) standart PRINTF :|%.10d| ", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_67) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%10.5d| ", -16);
    sprintf(data1, "02) standart PRINTF :|%10.5d| ", -16);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_68) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%5.10d| ", -16);
    sprintf(data1, "02) standart PRINTF :|%5.10d| ", -16);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_69) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%.2d| ", -1);
    sprintf(data1, "02) standart PRINTF : |%.2d| ", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_70) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%-10d| ", -80);
    sprintf(data1, "02) standart PRINTF : |%-10d| ", -80);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_71) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%-.10d| ", -80);
    sprintf(data1, "02) standart PRINTF : |%-.10d| ", -80);
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_72) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%.d| ", 0);
    sprintf(data1, "02) standart PRINTF : |%.d| ", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_73) {
    char data[100];
    char data1[100];

    s21_sprintf(data, "02) standart PRINTF : |%.d| ", 100);
    sprintf(data1, "02) standart PRINTF : |%.d| ", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_74) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%u| ", 34);
    sprintf(data1, "02) standart PRINTF : |%u| ", 34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_75) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%u| ", -34);
    sprintf(data1, "02) standart PRINTF : |%u| ", -34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_76) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%-u| ", 50);
    sprintf(data1, "02) standart PRINTF : |%-u| ", 50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_77) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%10u| ", 90);
    sprintf(data1, "02) standart PRINTF : |%10u| ", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_78) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%.10u| ", 90);
    sprintf(data1, "02) standart PRINTF : |%.10u| ", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_79) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%15u| ", -100);
    sprintf(data1, "02) standart PRINTF : |%15u| ", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_80) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%10.5u| ", 52);
    sprintf(data1, "02) standart PRINTF : |%10.5u| ", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_81) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%5.10u| ", 52);
    sprintf(data1, "02) standart PRINTF : |%5.10u| ", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_82) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%20.15u| ", -100000);
    sprintf(data1, "02) standart PRINTF : |%20.15u| ", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_83) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%15.20u| ", -100000);
    sprintf(data1, "02) standart PRINTF : |%15.20u| ", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_84) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%-10u| ", 144);
    sprintf(data1, "02) standart PRINTF : |%-10u| ", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_85) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%-.10u| ", 144);
    sprintf(data1, "02) standart PRINTF : |%-.10u| ", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_86) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%-20u| ", -20000000);
    sprintf(data1, "02) standart PRINTF : |%-20u| ", -20000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_87) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF :|%u| ", 0);
    sprintf(data1, "02) standart PRINTF :|%u| ", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_88) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%.u| ", 0);
    sprintf(data1, "02) standart PRINTF : |%.u| ", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_89) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%10u| ", 0);
    sprintf(data1, "02) standart PRINTF : |%10u| ", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_90) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%.u| ", 88);
    sprintf(data1, "02) standart PRINTF : |%.u| ", 88);
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_91) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "02) standart PRINTF : |%.3s| ", "21");
    sprintf(data1, "02) standart PRINTF : |%.3s| ", "21");
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_92) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%u| ", -1);
    sprintf(data1, "|%u| ", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_93) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%u| ", -1);
    sprintf(data1, "|%u| ", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_94) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);

    s21_sprintf(data, "|%20.2f| ", 324.345);
    sprintf(data1, "|%20.2f| ", 324.345);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_95) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%10f| ", 324.0000343);
    sprintf(data1, "|%10f| ", 324.0000343);
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_96) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%10.3f| ", 324.34323234423);
    sprintf(data1, "|%10.3f| ", 324.34323234423);
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_98) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%-1.10f| ", 324.343);
    sprintf(data1, "|%-1.10f| ", 324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_99) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%-1.10f| ", -324.343);
    sprintf(data1, "|%-1.10f| ", -324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_100) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%.10f| ", -324.343);
    sprintf(data1, "|%.10f| ", -324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_101) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%.19f| ", 324.000345);
    sprintf(data1, "|%.19f| ", 324.000345);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_102) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|% 10f| ", 324.1);
    sprintf(data1, "|% 10f| ", 324.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_103) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%+10f| ", 324.1);
    sprintf(data1, "|%+10f| ", 324.1);
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_104) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%.0f| ", 324.1123132);
    sprintf(data1, "|%.0f| ", 324.1123132);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_105) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%10.10f| ", 320.3);
    sprintf(data1, "|%10.10f| ", 320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_106) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%-10.10f| ", 320.3);
    sprintf(data1, "|%-10.10f| ", 320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_107) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%-10.10f| ", 320.3);
    sprintf(data1, "|%-10.10f| ", 320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_108) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%-10.10f| ", -320.3);
    sprintf(data1, "|%-10.10f| ", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_109) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%.0f| ", -320.3);
    sprintf(data1, "|%.0f| ", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_110) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%.0f| ", -320.3);
    sprintf(data1, "|%.0f| ", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(s21_sprintf_test_112) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%5.1f| ", 324.324);
    sprintf(data1, "|%5.1f| ", 324.324);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_113) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "|%5.f| ", 0.0001);
    sprintf(data1, "|%5.f| ", 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

// GENERAL CHECK
START_TEST(s21_sprintf_test_114) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    int a = 10, b = 20, c;
    c = a + b;
    sprintf(str, "Sum of %d and %d is %d", a, b, c);
    s21_sprintf(str1, "Sum of %d and %d is %d", a, b, c);
    ck_assert_str_eq(str, str1);
    sprintf(str, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u| ",
            "abra", 'e', 56, -43);
    s21_sprintf(str1, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u| ",
                "abra", 'e', 56, -43);
    ck_assert_str_eq(str, str1);
    sprintf(str, "Sum of %d and %d is %d", a, b, c);
    s21_sprintf(str1, "Sum of %d and %d is %d", a, b, c);
}
END_TEST

START_TEST(s21_sprintf_test_115) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u| ",
            "abra", 'e', 56, -43);
    s21_sprintf(str1, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u| ",
                "abra", 'e', 56, -43);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_116) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%.d| ", 0);
    s21_sprintf(str1, "|%.d| ", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST


// CHECK U

START_TEST(s21_sprintf_test_117) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%8s| ", "abra");
    s21_sprintf(str1, "|%8s| ", "abra");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_118) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%8s| ", "abrafdefgbr");
    s21_sprintf(str1, "|%8s| ", "abrafdefgbr");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_119) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%8s| ", "abra");
    s21_sprintf(str1, "|%8s| ", "abra");
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test_120) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%.0s| ",  "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%.0s| ",  "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_121) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "%i", 0);
    s21_sprintf(str1, "%i", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_122) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%c| ", 'a');
    s21_sprintf(str1, "|%c| ", 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_129) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    for (int i = -101; i <= 101; i++) {
        sprintf(str, "%+i", i);
        s21_sprintf(str1, "%+i", i);
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(s21_sprintf_test_130) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    for (int i = -101; i <= 101; i++) {
        sprintf(str, "%+d", i);
        s21_sprintf(str1, "%+d", i);
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(s21_sprintf_test_131) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, " %+d %+i %+d %+d", 2147483647, -2147483647, 21, 0);
    s21_sprintf(str1, " %+d %+i %+d %+d", 2147483647, -2147483647, 21, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_132) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, " %+li ", 9223372036854775807);
    s21_sprintf(str1, " %+li ", 9223372036854775807);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_133) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, " %+ld ", 9223372036854775807);
    s21_sprintf(str1, " %+ld ", 9223372036854775807);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_134) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, " %+-5d %+-5i", -7, 0);
    s21_sprintf(str1, " %+-5d %+-5i", -7, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_135) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    sprintf(str, "|%u| ",   10);
    s21_sprintf(str1, "|%u| ",   10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(s21_sprintf_test_136) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    for (int i = -101; i <= 101;) {
        sprintf(str, "% d", i);
        s21_sprintf(str1, "% d", i);
        i = i+7;
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(s21_sprintf_test_137) {
    char str[100];
    char str1[100];
    s21_memset(str, '\0', 100);
    s21_memset(str1, '\0', 100);
    for (int i = -101; i <= 101;) {
        sprintf(str, "% -i % -d % -5d", i, i+1, 143646235);
        s21_sprintf(str1, "% -i % -d % -5d", i, i+1, 143646235);
        i = i+7;
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(s21_sprintf_test_138) {
    char data[100];
    char data1[100];
    s21_memset(data, '\0', 100);
    s21_memset(data1, '\0', 100);
    s21_sprintf(data, "%-3.1s", "\0");
    sprintf(data1, "%-3.1s", "\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_139) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%li", 100000000000000000);
    sprintf(data1, "%li", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_140) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%lu", 100000000000000000);
    sprintf(data1, "%lu", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_141) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%ld", 100000000000000000);
    sprintf(data1, "%ld", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_142) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    short int i = -30000;
    s21_sprintf(data, "%hi", i);
    sprintf(data1, "%hi", i);

    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_143) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    short int i = -30000;
    s21_sprintf(data, "%hu", i);
    sprintf(data1, "%hu", i);

    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_144) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    short int i = -30000;
    s21_sprintf(data, "%hd", i);
    sprintf(data1, "%hd", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_145) {
    char str1[100];
    char str2[100];
    s21_memset(str1, '\0', 100);
    s21_memset(str2, '\0', 100);
    wchar_t a = L'汉';
    int num = s21_sprintf(str1, "%lc", a);
    int num1 = sprintf(str2, "%lc", a);
    ck_assert_int_eq(num, num1);
    ck_assert_str_eq(str1, str2);

    s21_memset(str1, '\0', 100);
    s21_memset(str2, '\0', 100);
    num = s21_sprintf(str1, "%5lc", a);
    num1 = sprintf(str2, "%5lc", a);
    ck_assert_int_eq(num, num1);

    s21_memset(str1, '\0', 100);
    s21_memset(str2, '\0', 100);
    num = s21_sprintf(str1, "%-5lc", a);
    num1 = sprintf(str2, "%-5lc", a);
    ck_assert_int_eq(num, num1);

    s21_memset(str1, '\0', 100);
    s21_memset(str2, '\0', 100);
    num = s21_sprintf(str1, "%-5lc%s", a, "Hello");
    num1 = sprintf(str2, "%-5lc%s", a, "Hello");
    ck_assert_int_eq(num, num1);

    s21_memset(str1, '\0', 100);
    s21_memset(str2, '\0', 100);
    wchar_t* s = L"汉汉汉";
    s21_sprintf(str1, "%-5ls%s", s, "Hello");
    sprintf(str2, "%-5ls%s", s, "Hello");
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_test_146) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%10%");
    ck_assert_str_eq(data, "         %");
}
END_TEST

START_TEST(s21_sprintf_test_147) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    float num = -0.0/0.0;
    s21_sprintf(data, "%f", num);
    sprintf(data1, "%f", num);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_148) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    float num = 0.0/0.0;
    s21_sprintf(data, "%10f", num);
    sprintf(data1, "%10f", num);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_150) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    float num = 1.0/0.0;
    s21_sprintf(data, "%10f", num);
    sprintf(data1, "%10f", num);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_151) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    char *null = s21_NULL;
    s21_sprintf(data, "%s", null);
    sprintf(data1, "%s", null);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_152) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%.5f", 123.0456789);
    sprintf(data1, "%.5f", 123.0456789);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_154) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%.f", 123.5000000000);
    sprintf(data1, "%.f", 123.5000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_155) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%.7f", 123.0);
    sprintf(data1, "%.7f", 123.0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_156) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%.f", 129.500000000);
    sprintf(data1, "%.f", 129.500000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(s21_sprintf_test_157) {
    char data[200];
    char data1[200];
    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%.f", 999.99);
    sprintf(data1, "%.f", 999.99);
    ck_assert_str_eq(data, data1);

    s21_memset(data, '\0', 200);
    s21_memset(data1, '\0', 200);
    s21_sprintf(data, "%.20u", 10);
    sprintf(data1, "%.20u", 10);
    ck_assert_str_eq(data, data1);
}
END_TEST


// функция для suite
Suite *f_example_suite_create() {
    Suite *s1 = suite_create("Test_string");
    TCase *StrLenTest = tcase_create("STRLEN");
    TCase *StrChrTest = tcase_create("STRCHR");
    TCase *StrSpnTest = tcase_create("STRSPN");
    TCase *StrсSpnTest = tcase_create("STRСSPN");
    TCase *MemCpyTest = tcase_create("MEMCPY");
    TCase *StrCatTest = tcase_create("STRCAT");
    TCase *MemcmpTest = tcase_create("MEMCMP");
    TCase *StrncatTest = tcase_create("STRNCAT");
    TCase *StrncpyTest = tcase_create("STRNCPY");
    TCase *StrrchrTest = tcase_create("STRRCHR");
    TCase *memmovetest = tcase_create("MEMMOVE");
    TCase *strstrtest = tcase_create("STRSTR");
    TCase *strcmptest = tcase_create("STRCMP");
    TCase *memchrtest = tcase_create("MEMCHR");
    TCase *strcpytest = tcase_create("STRCPY");
    TCase *strpbrktest = tcase_create("STRPBRK");
    TCase *StrnCmpTest = tcase_create("STRNCMP");
    TCase *MemSetTest = tcase_create("MEMSET");
    TCase *StrTokTest = tcase_create("STRTOK");
    TCase *strerrortest = tcase_create("STRERROR");
    TCase *to_uppertest = tcase_create("TOUPPER");
    TCase *inserttest = tcase_create("INSERT");
    TCase *to_lowertest = tcase_create("TOLOWER");
    TCase *trimtest = tcase_create("TRIM");
    suite_add_tcase(s1, StrLenTest);
    tcase_add_test(StrLenTest, STRLENTest1);
    tcase_add_test(StrLenTest, STRLENTest2);
    tcase_add_test(StrLenTest, STRLENTest3);
    tcase_add_test(StrLenTest, STRLENTest4);
    tcase_add_test(StrLenTest, STRLENTest5);
    tcase_add_test(StrLenTest, STRLENTest6);
    suite_add_tcase(s1, StrChrTest);
    tcase_add_test(StrChrTest, STRCHRTest1);
    tcase_add_test(StrChrTest, STRCHRTest2);
    tcase_add_test(StrChrTest, STRCHRTest3);
    tcase_add_test(StrChrTest, STRCHRTest4);
    tcase_add_test(StrChrTest, STRCHRTest5);
    tcase_add_test(StrChrTest, STRCHRTest6);
    suite_add_tcase(s1, StrSpnTest);
    tcase_add_test(StrSpnTest, STRSPNTest1);
    tcase_add_test(StrSpnTest, STRSPNTest2);
    tcase_add_test(StrSpnTest, STRSPNTest3);
    tcase_add_test(StrSpnTest, STRSPNTest4);
    tcase_add_test(StrSpnTest, STRSPNTest5);
    tcase_add_test(StrSpnTest, STRSPNTest6);
    tcase_add_test(StrSpnTest, STRSPNTest7);
    tcase_add_test(StrSpnTest, STRSPNTest8);
    suite_add_tcase(s1, StrсSpnTest);
    tcase_add_test(StrсSpnTest, STRCSPNTest1);
    tcase_add_test(StrсSpnTest, STRCSPNTest2);
    tcase_add_test(StrсSpnTest, STRCSPNTest3);
    tcase_add_test(StrсSpnTest, STRCSPNTest4);
    tcase_add_test(StrсSpnTest, STRCSPNTest5);
    tcase_add_test(StrсSpnTest, STRCSPNTest6);
    suite_add_tcase(s1, MemCpyTest);
    tcase_add_test(MemCpyTest, MEMCPYTest1);
    tcase_add_test(MemCpyTest, MEMCPYTest2);
    tcase_add_test(MemCpyTest, MEMCPYTest3);
    tcase_add_test(MemCpyTest, MEMCPYTest4);
    tcase_add_test(MemCpyTest, MEMCPYTest5);
    suite_add_tcase(s1, StrCatTest);
    tcase_add_test(StrCatTest, STRCATTest1);
    tcase_add_test(StrCatTest, STRCATTest2);
    tcase_add_test(StrCatTest, STRCATTest3);
    tcase_add_test(StrCatTest, STRCATTest4);
    tcase_add_test(StrCatTest, STRCATTest5);
    suite_add_tcase(s1, MemcmpTest);
    tcase_add_test(MemcmpTest, MEMCMPTest1);
    tcase_add_test(MemcmpTest, MEMCMPTest2);
    tcase_add_test(MemcmpTest, MEMCMPTest3);
    tcase_add_test(MemcmpTest, MEMCMPTest4);
    tcase_add_test(MemcmpTest, MEMCMPTest5);
    tcase_add_test(MemcmpTest, MEMCMPTest6);
    tcase_add_test(MemcmpTest, MEMCMPTest7);
    tcase_add_test(MemcmpTest, MEMCMPTest8);
    tcase_add_test(MemcmpTest, MEMCMPTest9);
    tcase_add_test(MemcmpTest, MEMCMPTest10);
    suite_add_tcase(s1, StrncatTest);
    tcase_add_test(StrncatTest, STRNCATTest1);
    tcase_add_test(StrncatTest, STRNCATTest2);
    tcase_add_test(StrncatTest, STRNCATTest3);
    tcase_add_test(StrncatTest, STRNCATTest4);
    tcase_add_test(StrncatTest, STRNCATTest5);
    suite_add_tcase(s1, StrncpyTest);
    tcase_add_test(StrncpyTest, STRNCPYTest1);
    tcase_add_test(StrncpyTest, STRNCPYTest2);
    tcase_add_test(StrncpyTest, STRNCPYTest3);
    tcase_add_test(StrncpyTest, STRNCPYTest4);
    tcase_add_test(StrncpyTest, STRNCPYTest5);
    suite_add_tcase(s1, StrrchrTest);
    tcase_add_test(StrrchrTest, STRRCHRTest1);
    tcase_add_test(StrrchrTest, STRRCHRTest2);
    tcase_add_test(StrrchrTest, STRRCHRTest3);
    tcase_add_test(StrrchrTest, STRRCHRTest4);
    tcase_add_test(StrrchrTest, STRRCHRTest5);
    suite_add_tcase(s1, memmovetest);
    tcase_add_test(memmovetest, MEMMOVETest1);
    tcase_add_test(memmovetest, MEMMOVETest2);
    tcase_add_test(memmovetest, MEMMOVETest3);
    tcase_add_test(memmovetest, MEMMOVETest4);
    tcase_add_test(memmovetest, MEMMOVETest5);
    tcase_add_test(memmovetest, MEMMOVETest6);
    tcase_add_test(memmovetest, MEMMOVETest7);
    tcase_add_test(memmovetest, MEMMOVETest8);
    tcase_add_test(memmovetest, MEMMOVETest9);
    tcase_add_test(memmovetest, MEMMOVETest10);
    suite_add_tcase(s1, strstrtest);
    tcase_add_test(strstrtest, STRSTRTest1);
    tcase_add_test(strstrtest, STRSTRTest2);
    tcase_add_test(strstrtest, STRSTRTest3);
    tcase_add_test(strstrtest, STRSTRTest4);
    tcase_add_test(strstrtest, STRSTRTest5);
    suite_add_tcase(s1, strcmptest);
    tcase_add_test(strcmptest, STRCMPTest1);
    tcase_add_test(strcmptest, STRCMPTest2);
    tcase_add_test(strcmptest, STRCMPTest3);
    tcase_add_test(strcmptest, STRCMPTest4);
    tcase_add_test(strcmptest, STRCMPTest5);
    tcase_add_test(strcmptest, STRCMPTest6);
    suite_add_tcase(s1, memchrtest);
    tcase_add_test(memchrtest, MEMCHRTest1);
    tcase_add_test(memchrtest, MEMCHRTest2);
    tcase_add_test(memchrtest, MEMCHRTest3);
    tcase_add_test(memchrtest, MEMCHRTest4);
    tcase_add_test(memchrtest, MEMCHRTest5);
    suite_add_tcase(s1, strcpytest);
    tcase_add_test(strcpytest, STRCPYTest1);
    tcase_add_test(strcpytest, STRCPYTest2);
    tcase_add_test(strcpytest, STRCPYTest3);
    tcase_add_test(strcpytest, STRCPYTest4);
    suite_add_tcase(s1, strpbrktest);
    tcase_add_test(strpbrktest, STRPBRKTest1);
    tcase_add_test(strpbrktest, STRPBRKTest2);
    tcase_add_test(strpbrktest, STRPBRKTest3);
    tcase_add_test(strpbrktest, STRPBRKTest4);
    suite_add_tcase(s1, StrnCmpTest);
    tcase_add_test(StrnCmpTest, STRNCMPTest1);
    tcase_add_test(StrnCmpTest, STRNCMPTest2);
    tcase_add_test(StrnCmpTest, STRNCMPTest3);
    tcase_add_test(StrnCmpTest, STRNCMPTest4);
    tcase_add_test(StrnCmpTest, STRNCMPTest5);
    tcase_add_test(StrnCmpTest, STRNCMPTest6);
    tcase_add_test(StrnCmpTest, STRNCMPTest7);
    tcase_add_test(StrnCmpTest, STRNCMPTest8);
    suite_add_tcase(s1, MemSetTest);
    tcase_add_test(MemSetTest, MEMSETTest1);
    tcase_add_test(MemSetTest, MEMSETTest2);
    tcase_add_test(MemSetTest, MEMSETTest3);
    tcase_add_test(MemSetTest, MEMSETTest4);
    tcase_add_test(MemSetTest, MEMSETTest5);
    tcase_add_test(MemSetTest, MEMSETTest6);
    tcase_add_test(MemSetTest, MEMSETTest7);
    suite_add_tcase(s1, StrTokTest);
    tcase_add_test(StrTokTest, STRTOKTest2);
    tcase_add_test(StrTokTest, STRTOKTest3);
    tcase_add_test(StrTokTest, STRTOKTest4);
    tcase_add_test(StrTokTest, STRTOKTest5);
    tcase_add_test(StrTokTest, STRTOKTest6);
    suite_add_tcase(s1, strerrortest);
    tcase_add_test(strerrortest, STRERRORTest2);
    tcase_add_test(strerrortest, STRERRORTest3);
    suite_add_tcase(s1, to_uppertest);
    tcase_add_test(to_uppertest, TOUPPERTest1);
    tcase_add_test(to_uppertest, TOUPPERTest2);
    tcase_add_test(to_uppertest, TOUPPERTest3);
    tcase_add_test(to_uppertest, TOUPPERTest4);
    tcase_add_test(to_uppertest, TOUPPERTest5);
    tcase_add_test(to_uppertest, TOUPPERTest6);
    tcase_add_test(to_uppertest, TOUPPERTest7);
    suite_add_tcase(s1, inserttest);
    tcase_add_test(inserttest, INSERTTest1);
    tcase_add_test(inserttest, INSERTTest2);
    tcase_add_test(inserttest, INSERTTest3);
    tcase_add_test(inserttest, INSERTTest4);
    tcase_add_test(inserttest, INSERTTest6);
    tcase_add_test(inserttest, INSERTTest7);
    suite_add_tcase(s1, to_lowertest);
    tcase_add_test(to_lowertest, TOLOWERTest1);
    tcase_add_test(to_lowertest, TOLOWERTest2);
    tcase_add_test(to_lowertest, TOLOWERTest3);
    tcase_add_test(to_lowertest, TOLOWERTest4);
    tcase_add_test(to_lowertest, TOLOWERTest5);
    tcase_add_test(to_lowertest, TOLOWERTest6);
    tcase_add_test(to_lowertest, TOLOWERTest7);
    suite_add_tcase(s1, trimtest);

    tcase_add_test(trimtest, TRIMTest13);
    return s1;
}


Suite *example_suite_create() {
    Suite *s1 = suite_create("Test_sprintf");
    TCase *s21_sprintf_test = tcase_create("SPRINTF2");

    suite_add_tcase(s1, s21_sprintf_test);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_2);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_3);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_4);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_5);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_6);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_8);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_10);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_11);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_12);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_13);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_15);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_16);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_18);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_19);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_20);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_21);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_22);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_23);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_24);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_25);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_26);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_28);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_29);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_30);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_31);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_32);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_33);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_34);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_35);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_36);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_37);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_38);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_39);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_40);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_41);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_42);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_43);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_44);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_45);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_46);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_47);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_48);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_49);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_50);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_51);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_52);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_53);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_54);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_55);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_56);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_57);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_58);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_59);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_60);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_61);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_62);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_63);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_64);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_65);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_66);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_67);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_68);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_69);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_70);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_71);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_72);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_73);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_74);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_75);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_76);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_77);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_78);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_79);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_80);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_81);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_82);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_83);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_84);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_85);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_86);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_87);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_88);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_89);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_90);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_91);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_92);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_93);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_94);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_95);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_96);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_98);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_99);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_100);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_101);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_102);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_103);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_104);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_105);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_106);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_107);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_108);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_109);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_110);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_112);
    tcase_add_test(s21_sprintf_test, s21_sprintf_test_113);
    return s1;
}

Suite *example_suite_create2() {
    Suite *s1 = suite_create("Test_sprintf_part2");
    TCase *s21_sprintf_test_1 = tcase_create("SPRINTF1");
    TCase *s21_sprintf_test_3 = tcase_create("SPRINTF3");
    suite_add_tcase(s1, s21_sprintf_test_1);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_114);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_115);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_116);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_117);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_118);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_119);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_120);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_121);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_122);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_129);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_130);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_131);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_132);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_133);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_134);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_135);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_136);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_137);
    tcase_add_test(s21_sprintf_test_1, s21_sprintf_test_138);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_139);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_140);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_141);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_142);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_143);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_144);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_145);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_146);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_147);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_148);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_150);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_151);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_152);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_154);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_155);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_156);
    tcase_add_test(s21_sprintf_test_3, s21_sprintf_test_157);
    suite_add_tcase(s1, s21_sprintf_test_3);

    return s1;
}

int main() {
    Suite *s1 = example_suite_create();
    Suite *s4 = example_suite_create2();
    Suite *s2 = f_example_suite_create();

    // Runner
    SRunner *runner = srunner_create(s1);
    SRunner *runner2 = srunner_create(s4);
    SRunner *f_runner = srunner_create(s2);

    int number_failed;
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    srunner_run_all(runner2, CK_NORMAL);
    number_failed = number_failed + srunner_ntests_failed(runner2);
    srunner_free(runner2);
    srunner_run_all(f_runner, CK_NORMAL);
    number_failed = number_failed + srunner_ntests_failed(f_runner);
    srunner_free(f_runner);

    return number_failed == 0 ? 0 : 1;
}
