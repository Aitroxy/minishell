/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** display_base.c
*/
#include <stdarg.h>
#include "../../include/my_printf.h"

int display_hex_upper(va_list ap)
{
    int stock_return = 0;

    stock_return = my_put_base(
        va_arg(ap, unsigned long long int), "0123456789ABCDEF");
    return (stock_return);
}

int display_hex_lower(va_list ap)
{
    int stock_return;

    stock_return = my_put_base(
        va_arg(ap, unsigned long long int), "0123456789abcdef");
    return (stock_return);
}

int display_octal(va_list ap)
{
    int stock_return;

    stock_return = my_put_base(
        va_arg(ap, unsigned long long int), "01234567");
    return (stock_return);
}

int display_decimal(va_list ap)
{
    int stock_return;

    stock_return = my_put_base(
        va_arg(ap, unsigned long long int), "0123456789");
    return (stock_return);
}

int display_binary(va_list ap)
{
    int stock_return;

    stock_return = my_put_base(
        va_arg(ap, unsigned long long int), "01");
    return (stock_return);
}
