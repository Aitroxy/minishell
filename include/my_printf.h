/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-bsmyprintf-guillyann.ferrere
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

typedef int (*ptr_function_t)(va_list);
typedef struct flag_s {
    char flag;
    ptr_function_t print_func;
}flag_t;

int my_putchar(char c);
int my_putstr(char const *str);
int my_putstr_invisible(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int display_digit(va_list ap);
int display_char(va_list ap);
int display_str(va_list ap);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_put_base(unsigned long long int nb, char const *base);
int display_hex_plus(va_list ap);
int display_hex_upper(va_list ap);
int display_hex_lower(va_list ap);
int display_octal(va_list ap);
int display_decimal(va_list ap);
int display_binary(va_list ap);
int display_str_invisible(va_list ap);
int display_percent(va_list ap);
int my_printf(const char *format, ...);
int my_vprintf(char const *format, va_list ap);
int print_formatted(va_list ap, char const flag);

#endif
