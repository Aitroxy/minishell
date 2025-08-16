/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** display.c
*/
#include <stdarg.h>
#include "../../include/my_printf.h"

int display_digit(va_list ap)
{
    int stock_return = 0;

    stock_return = my_put_nbr(va_arg(ap, int));
    return (stock_return);
}

int display_char(va_list ap)
{
    int stock_return = 0;

    stock_return = my_putchar(va_arg(ap, int));
    return (stock_return);
}

int display_str(va_list ap)
{
    int stock_return = 0;

    stock_return = my_putstr(va_arg(ap, char const *));
    return (stock_return);
}

int display_str_invisible(va_list ap)
{
    int stock_return = 0;

    stock_return = my_putstr_invisible(va_arg(ap, char const *));
    return (stock_return);
}

int display_percent(va_list ap)
{
    int stock_return = 0;
    (void)ap;

    stock_return = my_putchar('%');
    return (stock_return);
}
