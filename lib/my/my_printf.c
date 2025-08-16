/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-bsmyprintf-guillyann.ferrere
** File description:
** my_printf.c
*/
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my_printf.h"

ptr_function_t get_print_func(char const flag)
{
    const flag_t flag_function[] = {
        {'d', &display_digit}, {'i', &display_digit},
        {'c', &display_char}, {'X', &display_hex_upper},
        {'s', &display_str}, {'x', &display_hex_lower},
        {'o', &display_octal}, {'u', &display_decimal},
        {'b', &display_binary}, {'C', &display_char}, {'%', &display_percent},
        {'S', &display_str_invisible}, {'p', &display_hex_plus},
        {0, NULL}
    };

    for (int i = 0; flag_function[i].flag != 0; i++) {
        if (flag == flag_function[i].flag)
            return flag_function[i].print_func;
    }
    return NULL;
}

int print_formatted(va_list ap, char const flag)
{
    ptr_function_t print_func = get_print_func(flag);

    if (print_func != NULL) {
        return print_func(ap);
    }
    return (0);
}

int my_vprintf(char const *format, va_list ap)
{
    int length = 0;
    int i = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            length += print_formatted(ap, format[i + 1]);
            i++;
        } else {
            length += my_putchar(format[i]);
        }
        if (format[i] != '\0')
            i++;
    }
    return length;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int length = 0;

    va_start(ap, format);
    length = my_vprintf(format, ap);
    va_end(ap);
    return (length);
}
